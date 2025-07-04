const express = require('express');
const router = express.Router();

// Login page
router.get('/organiser/login', (req, res) => {
  res.render('login', { error: null });
});

// Handle login submission
router.post('/organiser/login', (req, res) => {
  const { username, password } = req.body;

  const sql = `SELECT * FROM organisers WHERE username = ?`;
  global.db.get(sql, [username], (err, user) => {
    if (err) {
      console.error(err);
      return res.status(500).send("Database error");
    }

    // Simple password check (plaintext for now)
    if (!user || user.password !== password) {
      return res.render('login', { error: 'Invalid username or password' });
    }

    // ✅ Set session values
    req.session.isOrganiser = true;
    req.session.organiserId = user.id;
    req.session.organiserUsername = user.username;

    return res.redirect('/organiser');
  });
});

// Logout
router.get('/logout', (req, res) => {
  req.session.destroy(() => {
    res.redirect('/organiser/login');
  });
});

module.exports = router;
