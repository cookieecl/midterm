// build-db.js
const fs = require('fs');
const sqlite3 = require('sqlite3').verbose();

const DB_FILE = './database.db';
const SQL_FILE = './db_schema.sql';

const schema = fs.readFileSync(SQL_FILE, 'utf8');

const db = new sqlite3.Database(DB_FILE, (err) => {
  if (err) {
    console.error("❌ Error opening database:", err.message);
    process.exit(1);
  }
});

db.exec(schema, (err) => {
  if (err) {
    console.error("❌ Error executing schema:", err.message);
    process.exit(1);
  } else {
    console.log("✅ Database schema applied successfully!");
    db.close();
  }
});
