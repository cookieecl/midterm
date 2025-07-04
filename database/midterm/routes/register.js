const express = require('express');
const router = express.Router();

// GET /register - show registration form
router.get('/register', (req, res) => {
  res.render('register', { error: null });
});

// POST /register - handle registration submission
router.post('/register', (req, res) => {
  const { username, password, confirm_password } = req.body;

  if (!username || !password || !confirm_password) {
    return res.render('register', { error: 'Please fill out all fields.' });
  }

  if (password !== confirm_password) {
    return res.render('register', { error: 'Passwords do not match.' });
  }

  // Check if username already exists
  global.db.get('SELECT * FROM organisers WHERE username = ?', [username], (err, user) => {
    if (err) {
      console.error(err);
      return res.render('register', { error: 'Database error.' });
    }

    if (user) {
      return res.render('register', { error: 'Username already taken.' });
    }

    // Insert new organiser with plaintext password (simple but insecure!)
    global.db.run(
      'INSERT INTO organisers (username, password) VALUES (?, ?)',
      [username, password],
      (err2) => {
        if (err2) {
          console.error(err2);
          return res.render('register', { error: 'Registration failed.' });
        }
        res.redirect('/login');
      }
    );
  });
});

module.exports = router;
