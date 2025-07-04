const express = require('express');
const router = express.Router();

// Middleware to protect organiser routes
function ensureOrganiser(req, res, next) {
  if (req.session && req.session.isOrganiser) {
    return next();
  }
  res.redirect('/login');
}

// GET /login - render login page
router.get('/login', (req, res) => {
  res.render('login', { error: null });
});

// POST /login - process login form
router.post('/login', (req, res) => {
  const { username, password } = req.body;

  const sql = `SELECT * FROM organisers WHERE username = ?`;
  global.db.get(sql, [username], (err, user) => {
    if (err) {
      console.error(err);
      return res.status(500).send("Database error");
    }

    // Simple plaintext password check (for demo; consider hashing for production)
    if (!user || user.password !== password) {
      return res.render('login', { error: 'Invalid username or password' });
    }

    // Successful login: set session
    req.session.isOrganiser = true;
    req.session.organiserId = user.id;
    req.session.organiserUsername = user.username; // ✅ make sure this exists!
    res.redirect('/organiser');
  });
});

// GET /logout - clear session and redirect to login
router.get('/logout', (req, res) => {
  req.session.destroy(() => {
    res.redirect('/login');
  });
});

module.exports = { router, ensureOrganiser };
