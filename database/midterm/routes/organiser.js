const express = require('express');
const router = express.Router();

// GET /organiser - Organiser Home Page
router.get('/', (req, res) => {
  const sqlEvents = `SELECT * FROM events ORDER BY event_date ASC`;
  const sqlSettings = `SELECT * FROM settings WHERE id = 1`;

  global.db.all(sqlEvents, [], (err, rows) => {
    if (err) {
      console.error(err);
      return res.status(500).send("DB error");
    }

    // Separate draft and published events for display
    const drafts = rows.filter(event => event.status === 'draft');
    const published = rows.filter(event => event.status === 'published');

    // Now get site settings
    global.db.get(sqlSettings, [], (err2, settings) => {
      if (err2) {
        console.error(err2);
        return res.status(500).send("DB error");
      }

      // Pass drafts, published, and settings to the view
      res.render('organiser_published', {
        drafts,
        published,
        settings // Pass settings here
      });
    });
  });
});


// Route to create a new blank event and redirect to edit page
router.post('/events/create', (req, res) => {
    const now = new Date().toISOString();
    const sql = `
        INSERT INTO events 
        (title, description, status, event_date, created_at, updated_at, published_at, difficulty, children_friendly, max_capacity, full_price_count, full_price_price, child_price_count, child_price)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    `;
    // Insert with some default values or empty strings, status 'draft'
    const params = [
        '', '', 'draft', now, now, now, null, 'beginner', 'yes', 0, 0, 0.0, 0, 0.0
    ];
    global.db.run(sql, params, function(err) {
        if (err) {
            console.error(err);
            res.status(500).send("DB error");
        } else {
            // Redirect to edit page for newly created event
            res.redirect(`/organiser/events/edit/${this.lastID}?new=true`);
        }
    });
});

// Route to render the edit page (both for new and existing event)
// Route to render the edit page (both for new and existing event)
router.get('/events/edit/:id', (req, res) => {
    const id = req.params.id;
    const sqlEvent = `SELECT * FROM events WHERE id = ?`;
    const sqlBookings = `SELECT attendee_name, full_price_qty, child_qty FROM bookings WHERE event_id = ?`;

    global.db.get(sqlEvent, [id], (err, eventRow) => {
      if (err) {
        console.error(err);
        return res.status(500).send("DB error");
      }
      if (!eventRow) {
        return res.status(404).send("Event not found");
      }
  
      const justCreated = req.query.new === 'true';
      const readOnly = eventRow.status === 'published';
  
      // Now fetch all bookings (attendees) for this event

      global.db.all(sqlBookings, [id], (err2, attendees) => {
        if (err2) {
          console.error(err2);
          return res.status(500).send("Booking lookup failed");
        }
  
        // Render the page passing event info, readOnly flag, justCreated flag, and the attendees list
        res.render('event_edit', {
          event: eventRow,
          justCreated,
          readOnly,
          attendees
        });
      });
    });
  });
  


// Route to handle edit form submission (update event)
router.post('/events/edit/:id', (req, res) => {
  const id = req.params.id;

  global.db.get('SELECT status, published_at FROM events WHERE id = ?', [id], (err, existing) => {
    if (err || !existing) {
      console.error(err || "Event not found");
      return res.status(500).send("Event not found or DB error");
    }

    const {
      title = '',
      description = '',
      status = 'draft',
      event_date,
      difficulty = 'beginner',
      children_friendly = 'yes',
      max_capacity = 0,
      full_price_count = 0,
      full_price_price = 0.0,
      child_price_count = 0,
      child_price = 0.0
    } = req.body;

    const now = new Date().toISOString();

    // Only update published_at if transitioning from draft → published
    let publishedAt = existing.published_at;
    if (existing.status === 'draft' && status === 'published') {
      publishedAt = now;
    }

    const sql = `
      UPDATE events SET
        title = ?,
        description = ?,
        status = ?,
        event_date = ?,
        difficulty = ?,
        children_friendly = ?,
        max_capacity = ?,
        full_price_count = ?,
        full_price_price = ?,
        child_price_count = ?,
        child_price = ?,
        published_at = ?,
        updated_at = ?
      WHERE id = ?
    `;

    const params = [
      title,
      description,
      status,
      event_date,
      difficulty,
      children_friendly,
      max_capacity,
      full_price_count,
      full_price_price,
      child_price_count,
      child_price,
      publishedAt,
      now,
      id
    ];

    global.db.run(sql, params, function (err2) {
      if (err2) {
        console.error(err2);
        res.status(500).send("Update failed");
      } else {
        res.redirect('/organiser');
      }
    });
  });
});


  

// Delete event
router.post('/events/delete/:id', (req, res) => {
    const id = req.params.id;
    const sql = `DELETE FROM events WHERE id = ?`;
    global.db.run(sql, [id], (err) => {
        if (err) {
            console.error(err);
            res.status(500).send("DB error");
        } else {
            res.redirect('/organiser');
        }
    });
});

router.post('/events/:id/delete', (req, res) => {
    const eventId = req.params.id;
  
    const sql = 'DELETE FROM events WHERE id = ? AND status = "draft"';
    global.db.run(sql, [eventId], function (err) {
      if (err) {
        console.error(err);
        res.sendStatus(500);
      } else {
        res.sendStatus(200);
      }
    });
  });
  

router.post('/events/publish/:id', (req, res) => {
    const id = req.params.id;
    const now = new Date().toISOString();
    const sql = `
        UPDATE events
        SET status = 'published', published_at = ?
        WHERE id = ? AND status = 'draft'
    `;
    global.db.run(sql, [now, id], function(err) {
        if (err) {
            console.error(err);
            res.status(500).send("DB error");
        } else {
            res.redirect('/organiser');
        }
    });
});


module.exports = router;
