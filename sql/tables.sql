SET timezone = 'Africa/Nairobi';

CREATE TABLE IF NOT EXISTS product_type (
        id          serial PRIMARY KEY,
        type_id     VARCHAR(64) NOT NULL UNIQUE,
        type_name   VARCHAR ( 128 ) NOT NULL
);

CREATE TABLE IF NOT EXISTS product (
        id              serial PRIMARY KEY,
        barcode         VARCHAR ( 50 ) NOT NULL UNIQUE,
        product_name	VARCHAR ( 256 ) NOT NULL,
        product_unit	VARCHAR ( 36 ) NOT NULL,
        product_bp	REAL DEFAULT 0,
        product_sp	REAL DEFAULT 0,
        product_company	VARCHAR ( 128 ),
        type_id         VARCHAR(128) NOT NULL,
        product_deleted	boolean DEFAULT FALSE,

        FOREIGN KEY (type_id) REFERENCES product_type (type_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS stock (
        id              serial PRIMARY KEY,
        barcode         VARCHAR ( 50 ),
        stock_qty	INTEGER NOT NULL DEFAULT 0,
        last_update	TIMESTAMP WITH TIME ZONE NOT NULL,

        FOREIGN KEY(barcode) REFERENCES product (barcode) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS users (
        id                      serial PRIMARY KEY,
        firstname               VARCHAR (128) NOT NULL,
        lastname                VARCHAR (128) NOT NULL,
        username                VARCHAR (128) NOT NULL UNIQUE,
        password                VARCHAR (128) NOT NULL,
        phone_no                VARCHAR (128) NOT NULL,
        date_added              TIMESTAMP WITH TIME ZONE NOT NULL,
        to_change_password	boolean DEFAULT FALSE,
        to_delete_account       boolean DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS priviledges (
        id                      serial PRIMARY KEY,
        username                VARCHAR (128) NOT NULL,
        can_add_user            boolean DEFAULT TRUE,
        can_remove_user         boolean DEFAULT FALSE,
        can_add_product         boolean DEFAULT TRUE,
        can_remove_product	boolean DEFAULT FALSE,
        can_add_stock           boolean DEFAULT TRUE,
        can_remove_sales        boolean DEFAULT FALSE,
        can_remove_stock	boolean DEFAULT FALSE,
        can_backup              boolean DEFAULT FALSE,

        FOREIGN KEY(username) REFERENCES users(username) ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE IF NOT EXISTS creditee (
        id              serial PRIMARY KEY,
        firstname	TEXT NOT NULL,
        lastname	TEXT NOT NULL,
        national_id	NUMERIC NOT NULL,
        phone_no	NUMERIC NOT NULL,
        amount_due	REAL DEFAULT 0,
        date_added      TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT (current_timestamp AT TIME ZONE 'Africa/Nairobi')
);

CREATE TABLE IF NOT EXISTS payment (
        id              serial PRIMARY KEY,
        cash            REAL,
        mpesa           REAL,
        cheque          REAL,
        credit          REAL,
        sales_id	VARCHAR (128) NOT NULL UNIQUE,
        deleted         boolean DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS sales (
        id              serial PRIMARY KEY,
        sales_id        VARCHAR (128) NOT NULL,
        barcode         VARCHAR ( 50 ),
        sales_date	TIMESTAMP NOT NULL,
        product_bp	REAL NOT NULL,
        product_sp	REAL NOT NULL,
        sale_qty	int NOT NULL,
        username	VARCHAR (128) NOT NULL,
        deleted         boolean DEFAULT FALSE,

        FOREIGN KEY(sales_id) REFERENCES payment (sales_id) ON UPDATE CASCADE ON DELETE CASCADE,
        FOREIGN KEY(username) REFERENCES users (username) ON UPDATE CASCADE ON DELETE SET NULL,
        FOREIGN KEY(barcode) REFERENCES product (barcode) ON UPDATE CASCADE ON DELETE SET NULL
);

CREATE TABLE IF NOT EXISTS mpesa (
        id              serial PRIMARY KEY,
        mpesa_id	VARCHAR (128) NOT NULL UNIQUE,
        sales_id	VARCHAR (128) NOT NULL,

        FOREIGN KEY(sales_id) REFERENCES payment (sales_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS credit (
        id              serial PRIMARY KEY,
        creditee_id	INTEGER,
        due_date	TIMESTAMP NOT NULL,
        sales_id	VARCHAR (128) NOT NULL,

        FOREIGN KEY (creditee_id) REFERENCES creditee (id) ON UPDATE CASCADE ON DELETE CASCADE,
        FOREIGN KEY(sales_id) REFERENCES payment (sales_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS notifications (
        id          serial PRIMARY KEY,
        level       INTEGER NOT NULL DEFAULT 0,
        message     TEXT NOT NULL,
        muted       boolean DEFAULT FALSE,
        solved      boolean DEFAULT FALSE,
        notify_date TIMESTAMP NOT NULL
);

CREATE TABLE IF NOT EXISTS messages (
        id          serial PRIMARY KEY,
        sender          TEXT NOT NULL,
        receiver        TEXT NOT NULL,
        date        TIMESTAMP NOT NULL,
        content     TEXT NOT NULL,
        has_read    boolean DEFAULT FALSE
);
