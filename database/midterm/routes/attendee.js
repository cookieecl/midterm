const express = require('express');
const router = express.Router();

router.get('/', (req, res) => {
    const query = `SELECT * FROM events WHERE status = 'published' ORDER BY event_date ASC`;

    db.all(query, (err, events) => {
        if (err) {
            console.error(err);
            return res.status(500).send("Internal Server Error");
        }
        res.render('attendee', { events });
    });
});

router.get('/event/:id', (req, res) => {
    const eventId = req.params.id;

    const query = `SELECT * FROM events WHERE id = ? AND status = 'published'`;

    db.get(query, [eventId], (err, event) => {
        if (err) {
            console.error(err);
            return res.status(500).send("Database error.");
        }
        if (!event) {
            return res.status(404).send("Event not found.");
        }

        res.render('attendee_event', { event, error: null });
    });
});

router.post('/event/:id', (req, res) => {
    const eventId = req.params.id;
    const { attendee_name, full_price_qty, child_qty } = req.body;

    const adultQty = parseInt(full_price_qty) || 0;
    const childQty = parseInt(child_qty) || 0;

    db.get(`SELECT * FROM events WHERE id = ?`, [eventId], (err, event) => {
        if (err) return res.status(500).send("Database error");
        if (!event) return res.status(404).send("Event not found");

        const updateTickets = `
            UPDATE events SET
                full_price_count = full_price_count + ?,
                child_price_count = child_price_count + ?
            WHERE id = ?
        `;
        const insertBooking = `
            INSERT INTO bookings (event_id, attendee_name, full_price_qty, child_qty)
            VALUES (?, ?, ?, ?)
        `;

        db.run(updateTickets, [adultQty, childQty, eventId], function(err) {
            if (err) return res.status(500).send("Could not update ticket counts");

            db.run(insertBooking, [eventId, attendee_name, adultQty, childQty], function(err) {
                if (err) return res.status(500).send("Could not save booking");

                res.redirect('/attendee');
            });
        });
    });
});

  

module.exports = router;