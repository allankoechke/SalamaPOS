BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "product_type" (
        "id"	serial PRIMARY KEY,
        "type_name"	INTEGER NOT NULL
);
CREATE TABLE IF NOT EXISTS "product" (
	"barcode"	TEXT,
	"product_name"	TEXT NOT NULL,
	"product_unit"	TEXT NOT NULL,
	"product_bp"	REAL NOT NULL,
	"product_sp"	REAL NOT NULL,
	"product_company"	TEXT,
	"product_deleted"	INTEGER DEFAULT 0,
	"type_id"	INTEGER,
	PRIMARY KEY("barcode"),
	FOREIGN KEY("type_id") REFERENCES "product_type"("id")
);
CREATE TABLE IF NOT EXISTS "stock" (
        "id"	serial PRIMARY KEY,
	"barcode"	TEXT,
	"stock_qty"	INTEGER NOT NULL,
	"last_update"	TEXT NOT NULL,
        FOREIGN KEY("barcode") REFERENCES "product"("barcode")
);
CREATE TABLE IF NOT EXISTS "notifications" (
        "id"	serial PRIMARY KEY,
	"level"	INTEGER NOT NULL DEFAULT 0,
	"message"	TEXT NOT NULL,
	"muted"	INTEGER DEFAULT 0,
	"solved"	INTEGER DEFAULT 0,
        "notify_date"	TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS "messages" (
        "id"	serial PRIMARY KEY,
	"to"	TEXT NOT NULL,
	"from"	TEXT NOT NULL,
	"content"	TEXT NOT NULL,
        "has_read"	INTEGER DEFAULT 0
);
CREATE TABLE IF NOT EXISTS "user" (
        "id"	serial PRIMARY KEY,
	"firstname"	TEXT NOT NULL,
	"lastname"	TEXT NOT NULL,
        "username"	TEXT NOT NULL UNIQUE,
	"password"	TEXT NOT NULL,
	"phone_no"	NUMERIC NOT NULL,
        "to_change_password"	INTEGER DEFAULT 0
);
CREATE TABLE IF NOT EXISTS "priviledges" (
        "id"	serial PRIMARY KEY,
	"username"	TEXT NOT NULL,
	"can_add_user"	INTEGER DEFAULT 0,
	"can_remove_user"	INTEGER DEFAULT 0,
	"can_add_product"	INTEGER DEFAULT 1,
	"can_remove_product"	INTEGER DEFAULT 0,
	"can_add_stock"	INTEGER DEFAULT 1,
	"can_remove_stock"	INTEGER DEFAULT 0,
        "can_backup"	INTEGER DEFAULT 0,
	FOREIGN KEY("username") REFERENCES "user"("username")
);
CREATE TABLE IF NOT EXISTS "creditee" (
        "id"	serial PRIMARY KEY,
	"firstname"	TEXT NOT NULL,
	"lastname"	TEXT NOT NULL,
	"national_id"	NUMERIC NOT NULL,
	"phone_no"	NUMERIC NOT NULL,
        "amount_due"	REAL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS "sales" (
        "id"	serial PRIMARY KEY,
        "barcode"	TEXT,
        "sales_date"	TEXT NOT NULL,
        "product_bp"	REAL NOT NULL,
        "product_sp"	REAL NOT NULL,
        "sale_qty"	REAL NOT NULL,
        "username"	TEXT,
        "deleted"	INTEGER DEFAULT 0,
        FOREIGN KEY("username") REFERENCES "user"("username"),
        FOREIGN KEY("barcode") REFERENCES "product"("barcode")
);
CREATE TABLE IF NOT EXISTS "payment" (
        "id"	serial PRIMARY KEY,
        "cash"	REAL,
        "mpesa"	REAL,
        "cheque"	REAL,
        "credit"	REAL,
        "sales_id"	INTEGER NOT NULL,
        "deleted"	INTEGER DEFAULT 0,
        FOREIGN KEY("sales_id") REFERENCES "sales"("id")
);
CREATE TABLE IF NOT EXISTS "mpesa" (
        "id"	serial PRIMARY KEY,
	"mpesa_id"	TEXT NOT NULL,
	"payment_id"	INTEGER NOT NULL,
        FOREIGN KEY("payment_id") REFERENCES "payment"("id")
);
CREATE TABLE IF NOT EXISTS "credit" (
        "id"	serial PRIMARY KEY,
	"creditee_id"	INTEGER,
	"due_date"	TEXT,
	"payment_id"	INTEGER NOT NULL,
	FOREIGN KEY("creditee_id") REFERENCES "creditee"("id"),
        FOREIGN KEY("payment_id") REFERENCES "payment"("id")
);

COMMIT;
