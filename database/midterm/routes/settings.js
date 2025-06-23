const express = require('express');
const router = express.Router();

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