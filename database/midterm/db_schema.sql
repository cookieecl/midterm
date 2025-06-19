
-- This makes sure that foreign_key constraints are observed and that errors will be thrown for violations
PRAGMA foreign_keys=ON;

BEGIN TRANSACTION;

-- Create your tables with SQL commands here (watch out for slight syntactical differences with SQLite vs MySQL)

-- Settings table
CREATE TABLE IF NOT EXISTS settings (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    site_name TEXT NOT NULL,
    site_description TEXT NOT NULL
);

-- Events table
CREATE TABLE IF NOT EXISTS events (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    description TEXT NOT NULL,
    status TEXT NOT NULL, --either draft or published (idk change to bool or no)
    event_date TEXT NOT NULL,
    created_at TEXT NOT NULL,
    published_at TEXT,
    difficulty TEXT NOT NULL, --either beginner, intermediate, or advance
    children_friendly TEXT NOT NULL, --either yes or no (idk bool or no)
    max_capacity INTEGER NOT NULL,
    full_price_count INTEGER NOT NULL,
    full_price_price REAL NOT NULL,
    child_price_count INTEGER NOT NULL,
    child_price REAL NOT NULL
);

-- Bookings table
CREATE TABLE IF NOT EXISTS bookings (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    event_id INTEGER NOT NULL,
    attendee_name TEXT NOT NULL,
    full_price_qty INTEGER NOT NULL,
    child_qty INTEGER NOT NULL,
    FOREIGN KEY (event_id) REFERENCES events(id)
);

-- CREATE TABLE IF NOT EXISTS users (
--     user_id INTEGER PRIMARY KEY AUTOINCREMENT,
--     user_name TEXT NOT NULL
-- );

-- CREATE TABLE IF NOT EXISTS email_accounts (
--     email_account_id INTEGER PRIMARY KEY AUTOINCREMENT,
--     email_address TEXT NOT NULL,
--     user_id  INT, --the user that the email account belongs to
--     FOREIGN KEY (user_id) REFERENCES users(user_id)
-- );

-- Insert default data (if necessary here)


INSERT INTO settings (site_name, site_description) VALUES
    ('Sugar Rush Studio', 'Baking classes designed to sweeten your skills');

-- Set up three users
-- INSERT INTO users ('user_name') VALUES ('Simon Star');
-- INSERT INTO users ('user_name') VALUES ('Dianne Dean');
-- INSERT INTO users ('user_name') VALUES ('Harry Hilbert');

-- Give Simon two email addresses and Diane one, but Harry has none
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('simon@gmail.com', 1); 
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('simon@hotmail.com', 1); 
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('dianne@yahoo.co.uk', 2); 

COMMIT;

