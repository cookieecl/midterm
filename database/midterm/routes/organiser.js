const express = require('express');
const router = express.Router();

// GET /organiser - Organiser Home Page
router.get('/', (req, res) => {
    const sql = `SELECT * FROM events ORDER BY event_date ASC`;

    global.db.all(sql, [], (err, rows) => {
        if (err) {
            console.error(err);
            return res.status(500).send("DB error");
        }

        // Separate draft and published events for display
        const drafts = rows.filter(event => event.status === 'draft');
        const published = rows.filter(event => event.status === 'published');

        res.render('organiser_published', {
            drafts: drafts,
            published: published,
        });
    });
});


// Route to create a new blank event and redirect to edit page
router.post('/events/create', (req, res) => {
    const now = new Date().toISOString();
    const sql = `
        INSERT INTO events 
        (title, description, status, event_date, created_at, difficulty, children_friendly, max_capacity, full_price_count, full_price_price, child_price_count, child_price)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    `;
    // Insert with some default values or empty strings, status 'draft'
    const params = [
        '', '', 'draft', now, now, 'beginner', 'yes', 0, 0, 0.0, 0, 0.0
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
  
    // First check if the event is already published
    global.db.get('SELECT status FROM events WHERE id = ?', [id], (err, row) => {
      if (err || !row) {
        console.error(err || "Event not found");
        return res.status(500).send("Event not found or DB error");
      }
  
      if (row.status === 'published') {
        // Prevent editing if published
        return res.status(400).send("Cannot edit a published event.");
      }
  
      // If not published, continue updating
      const {
        title, description, status, event_date, difficulty,
        children_friendly, max_capacity, full_price_count,
        full_price_price, child_price_count, child_price
      } = req.body;
  
      const now = new Date().toISOString();
  
      const sql = `
        UPDATE events SET
            title = ?,
            description = ?,
            status = ?,
            event_date = ?,
            difficulty = ?,
            children_friendly = ?,
            max_capacity = ?,
            full_price_price = ?,
            child_price = ?,
            published_at = CASE WHEN status = 'published' THEN ? ELSE published_at END
        WHERE id = ?
      `;
  
      const publishedAt = status === 'published' ? now : null;
  
      const params = [
        title, description, status, event_date, difficulty,
        children_friendly, max_capacity,
        full_price_price, child_price,
        publishedAt, id
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
