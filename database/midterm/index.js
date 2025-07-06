/**
* index.js
* Main entry point
* Sets up routing, middleware, database, and central error handling
*/

// Set up express, bodyparser, EJS, and middleware
const express = require('express');
const session = require('express-session');
const app = express();
const port = 3000;
var bodyParser = require("body-parser");
const { router: authRouter, ensureOrganiser } = require('./routes/auth');

// Middleware to parse URL-encoded request from login page
app.use(bodyParser.urlencoded({ extended: true }));

// Set the app to use ejs for rendering views (as the template engine)
app.set('view engine', 'ejs');

// Set location of static files
app.use(express.static(__dirname + '/public'));

// Configure and use the session middleware (for user login sessions)
app.use(session({
  secret: 'secretkey',
  resave: false,
  saveUninitialized: false,
}));

// Set up SQLite
// Items in the global namespace are accessible throught out the node application
const sqlite3 = require('sqlite3').verbose();
global.db = new sqlite3.Database('./database.db',function(err){
    if(err){
        console.error(err);
        process.exit(1); // Bail out we can't connect to the DB
    } else {
        console.log("Database connected");
        global.db.run("PRAGMA foreign_keys=ON"); // Tell SQLite to pay attention to foreign key constraints
    }
});

// Handle requests to the home page 
app.get('/', (req, res) => {
  global.db.get('SELECT site_name, site_description FROM settings LIMIT 1', (err, settings) => {
    if (err) {
      console.error(err);
      res.status(500).send("Database error");
    } else {
      res.render('home', { settings });
    }
  });
});

app.use('/images', express.static(__dirname + '/images'));

app.use(express.urlencoded({ extended: true }));

app.use(authRouter);

// Protect organiser routes:
app.use('/organiser', ensureOrganiser, require('./routes/organiser'));

// Add all the route handlers in usersRoutes to the app under the path /users
// const organiserRoutes = require('./routes/organiser');
// app.use('/organiser', organiserRoutes);

const attendeeRoutes = require('./routes/attendee');
app.use('/attendee', attendeeRoutes);

const settingRoutes = require('./routes/settings');
app.use('/organiser/settings', settingRoutes);

const registerRoutes = require('./routes/register');
app.use('/', registerRoutes);

// const usersRoutes = require('./routes/users');
// app.use('/users', usersRoutes);


// Make the web application listen for HTTP requests
app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})

