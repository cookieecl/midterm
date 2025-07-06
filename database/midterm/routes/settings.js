/**
 * organiserSettings.js
 * Route handler for organiser site settings.
 * Allows viewing and updating global site-level settings (name & description).
 */

const express = require('express');
const router = express.Router();

/**
 * @route   GET /organiser/settings
 * @desc    Fetch and display the current site settings
 */

// GET /organiser/settings - View Site Settings
router.get('/', (req, res) => {
  const sql = `SELECT * FROM settings WHERE id = 1`;
  global.db.get(sql, [], (err, row) => {
    if (err) {
      console.error(err);
      return res.status(500).send("DB error");
    }
    res.render('site_settings', { settings: row });
  });
});

router.get('/', (req, res) => {
  const sql = `SELECT * FROM settings WHERE id = 1`;

  global.db.get(sql, [], function (err, row) {
    if (err) {
      console.error("Database error:", err);
      return res.status(500).send("Internal server error while retrieving settings.");
    }

    // Render the settings page with the fetched row
    res.render('site_settings', { settings: row });
  });
});

/**
 * @route   POST /organiser/settings
 * @desc    Update site name and description in the settings table
 */
router.post('/', (req, res) => {
  const { site_name, site_description } = req.body;

  // Validate that required fields are not empty
  if (!site_name || !site_description) {
    return res.status(400).send("All fields are required.");
  }

  const sql = `UPDATE settings SET site_name = ?, site_description = ? WHERE id = 1`;

  global.db.run(sql, [site_name, site_description], function (err) {
    if (err) {
      console.error("Update error:", err);
      return res.status(500).send("Failed to update site settings.");
    }

    // Redirect to organiser homepage after successful update
    res.redirect('/organiser');
  });
});

// Export router to be used in main app
module.exports = router;



// POST /organiser/settings - Update Site Settings
router.post('/', (req, res) => {
  const { site_name, site_description } = req.body;
  if (!site_name || !site_description) {
    return res.status(400).send("All fields are required.");
  }

  const sql = `UPDATE settings SET site_name = ?, site_description = ? WHERE id = 1`;
  global.db.run(sql, [site_name, site_description], function (err) {
    if (err) {
      console.error(err);
      return res.status(500).send("Update failed");
    }
    res.redirect('/organiser');
  });
});

module.exports = router;