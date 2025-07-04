// middleware/auth.js
function ensureOrganiser(req, res, next) {
  if (req.session && req.session.isOrganiser) {
    return next();
  } else {
    return res.redirect('/login');
  }
}

module.exports = ensureOrganiser;
