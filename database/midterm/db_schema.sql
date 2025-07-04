
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
    updated_at TEXT NOT NULL,
    published_at TEXT,
    difficulty TEXT NOT NULL,
    children_friendly INTEGER NOT NULL,
    max_capacity INTEGER NOT NULL,
    full_price_count INTEGER NOT NULL,
    full_price_price REAL NOT NULL,
    child_price_count INTEGER NOT NULL,
    child_price REAL NOT NULL,
    organiser TEXT NOT NULL
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

-- Organizer username and passwords table
CREATE TABLE organisers (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  username TEXT NOT NULL UNIQUE,
  password TEXT NOT NULL
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

-- Insert organiser accounts
INSERT INTO organisers (username, password) VALUES ('angelline', 'angel001');
INSERT INTO organisers (username, password) VALUES ('emily', 'emily222');
INSERT INTO organisers (username, password) VALUES ('john', 'john456');
INSERT INTO organisers (username, password) VALUES ('michael', 'mikee7');
INSERT INTO organisers (username, password) VALUES ('tom', 'tom333');

-- Insert baking-themed events (some drafts, some published) for each organiser
INSERT INTO events (title, description, status, event_date, created_at, updated_at, published_at, difficulty, children_friendly, max_capacity, full_price_count, full_price_price, child_price_count, child_price, organiser)
VALUES
  -- angelline
  ('Cupcake Basics', 'Learn to bake fluffy cupcakes with vanilla buttercream.', 'published', '2025-07-10T10:00:00', '2025-06-27T17:59:12', '2025-06-30T21:03:19', '2025-06-30T21:04:31', 'beginner', 1, 12, 7, 30.00, 4, 20.00, 'angelline'),
  ('Macarons', 'French macarons with chocolate ganache filling.', 'draft', '2025-07-20T15:00:00', '2025-06-27T20:51:09', '2025-07-01T09:18:42', NULL, 'advance', 0, 12, 5, 45.00, 0, 0.00, 'angelline'),

  -- emily
  ('Sourdough', 'All about the basics including starter and carving.', 'published', '2025-07-15T15:00:00', '2025-06-28T11:23:42', '2025-07-01T16:15:19', '2025-07-01T16:15:59', 'intermediate', 0, 8, 4, 35.00, 0, 18.00, 'emily'),
  ('Cinnamon Rolls', 'Soft cinnamon rolls with cream cheese icing.', 'draft', '2025-07-22T12:00:00', '2025-06-29T09:12:03', '2025-07-01T21:09:47', NULL, 'beginner', 1, 10, 0, 25.00, 0, 0.00, 'emily'),

  -- john
  ('Croissant Perfection', 'Master laminated dough and bake golden croissants.', 'published', '2025-07-12T16:00:00', '2025-06-29T11:01:25', '2025-07-01T21:11:56', '2025-07-01T21:12:46', 'advance', 0, 8, 5, 40.00, 0, 25.00, 'john'),

  -- michael
  ('Bagel', 'Make New York-style bagels from scratch.', 'draft', '2025-07-25T12:00:00', '2025-06-29T20:03:52', '2025-06-29T20:03:52', NULL, 'intermediate', 0, 10, 0, 30.00, 0, 0.00, 'michael'),
  ('Kids Cookie Camp', 'Fun baking class for kids: sugar cookies and royal icing.', 'published', '2025-07-11T15:00:00', '2025-06-30T16:53:22', '2025-06-30T16:53:22', '2025-07-01T10:10:14', 'beginner', 1, 6, 2, 20.00, 4, 10.00, 'michael'),

  -- tom
  ('Lemon Tart Workshop', 'Lemon tarts with buttery pastry.', 'published', '2025-07-09T10:00:00', '2025-06-30T21:53:12', '2025-07-01T01:13:15', '2025-07-01T11:00:18', 'intermediate', 0, 10, 2, 32.00, 0, 16.00, 'tom');

INSERT INTO bookings (event_id, attendee_name, full_price_qty, child_qty) VALUES
  (1, 'Alice', 2, 1),
  (1, 'Frank', 3, 0),
  (1, 'Harl', 2, 3),
  (3, 'Gloria', 4, 0),
  (5, 'Karen', 1, 0),
  (5, 'Harl', 2, 0),
  (5, 'Alice', 2, 0),
  (7, 'Avery', 2, 4),
  (7, 'Alice', 2, 1),
  (8, 'Charles', 2, 0);

-- Set up three users
-- INSERT INTO users ('user_name') VALUES ('Simon Star');
-- INSERT INTO users ('user_name') VALUES ('Dianne Dean');
-- INSERT INTO users ('user_name') VALUES ('Harry Hilbert');

-- Give Simon two email addresses and Diane one, but Harry has none
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('simon@gmail.com', 1); 
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('simon@hotmail.com', 1); 
-- INSERT INTO email_accounts ('email_address', 'user_id') VALUES ('dianne@yahoo.co.uk', 2); 

COMMIT;

