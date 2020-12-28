--
-- PostgreSQL database dump
--

-- Dumped from database version 11.9
-- Dumped by pg_dump version 11.9

-- Started on 2020-12-28 13:52:39

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

DROP DATABASE salama;
--
-- TOC entry 3027 (class 1262 OID 17834)
-- Name: salama; Type: DATABASE; Schema: -; Owner: postgres
--

CREATE DATABASE salama WITH TEMPLATE = template0 ENCODING = 'UTF8' LC_COLLATE = 'English_Kenya.1252' LC_CTYPE = 'English_Kenya.1252';


ALTER DATABASE salama OWNER TO postgres;

\connect salama

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 217 (class 1259 OID 17999)
-- Name: credit; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.credit (
    id integer NOT NULL,
    creditee_id numeric NOT NULL,
    due_date timestamp without time zone NOT NULL,
    sales_id character varying(128) NOT NULL
);


ALTER TABLE public.credit OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 17997)
-- Name: credit_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.credit_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.credit_id_seq OWNER TO postgres;

--
-- TOC entry 3028 (class 0 OID 0)
-- Dependencies: 216
-- Name: credit_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.credit_id_seq OWNED BY public.credit.id;


--
-- TOC entry 219 (class 1259 OID 18020)
-- Name: credit_payments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.credit_payments (
    id integer NOT NULL,
    payment_timestamp timestamp without time zone NOT NULL,
    creditee_id numeric NOT NULL,
    payment_amount real NOT NULL,
    payment_due real NOT NULL
);


ALTER TABLE public.credit_payments OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 18018)
-- Name: credit_payments_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.credit_payments_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.credit_payments_id_seq OWNER TO postgres;

--
-- TOC entry 3029 (class 0 OID 0)
-- Dependencies: 218
-- Name: credit_payments_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.credit_payments_id_seq OWNED BY public.credit_payments.id;


--
-- TOC entry 209 (class 1259 OID 17934)
-- Name: creditee; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.creditee (
    id integer NOT NULL,
    firstname text NOT NULL,
    lastname text NOT NULL,
    national_id numeric NOT NULL,
    phone_no numeric NOT NULL,
    amount_due real DEFAULT 0,
    date_added timestamp with time zone DEFAULT timezone('Africa/Nairobi'::text, CURRENT_TIMESTAMP) NOT NULL
);


ALTER TABLE public.creditee OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 17932)
-- Name: creditee_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.creditee_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.creditee_id_seq OWNER TO postgres;

--
-- TOC entry 3030 (class 0 OID 0)
-- Dependencies: 208
-- Name: creditee_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.creditee_id_seq OWNED BY public.creditee.id;


--
-- TOC entry 221 (class 1259 OID 18036)
-- Name: login_history; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.login_history (
    id integer NOT NULL,
    login_time timestamp without time zone NOT NULL,
    username character varying(128) NOT NULL,
    is_login boolean DEFAULT true NOT NULL
);


ALTER TABLE public.login_history OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 18034)
-- Name: login_history_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.login_history_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.login_history_id_seq OWNER TO postgres;

--
-- TOC entry 3031 (class 0 OID 0)
-- Dependencies: 220
-- Name: login_history_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.login_history_id_seq OWNED BY public.login_history.id;


--
-- TOC entry 225 (class 1259 OID 18064)
-- Name: messages; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.messages (
    id integer NOT NULL,
    sender text NOT NULL,
    receiver text NOT NULL,
    date timestamp without time zone NOT NULL,
    content text NOT NULL,
    has_read boolean DEFAULT false
);


ALTER TABLE public.messages OWNER TO postgres;

--
-- TOC entry 224 (class 1259 OID 18062)
-- Name: messages_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.messages_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.messages_id_seq OWNER TO postgres;

--
-- TOC entry 3032 (class 0 OID 0)
-- Dependencies: 224
-- Name: messages_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.messages_id_seq OWNED BY public.messages.id;


--
-- TOC entry 215 (class 1259 OID 17984)
-- Name: mpesa; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.mpesa (
    id integer NOT NULL,
    mpesa_id character varying(128) NOT NULL,
    sales_id character varying(128) NOT NULL
);


ALTER TABLE public.mpesa OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 17982)
-- Name: mpesa_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.mpesa_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.mpesa_id_seq OWNER TO postgres;

--
-- TOC entry 3033 (class 0 OID 0)
-- Dependencies: 214
-- Name: mpesa_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.mpesa_id_seq OWNED BY public.mpesa.id;


--
-- TOC entry 223 (class 1259 OID 18050)
-- Name: notifications; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.notifications (
    id integer NOT NULL,
    level integer DEFAULT 0 NOT NULL,
    message text NOT NULL,
    muted boolean DEFAULT false,
    solved boolean DEFAULT false,
    notify_date timestamp without time zone NOT NULL
);


ALTER TABLE public.notifications OWNER TO postgres;

--
-- TOC entry 222 (class 1259 OID 18048)
-- Name: notifications_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.notifications_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.notifications_id_seq OWNER TO postgres;

--
-- TOC entry 3034 (class 0 OID 0)
-- Dependencies: 222
-- Name: notifications_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.notifications_id_seq OWNED BY public.notifications.id;


--
-- TOC entry 211 (class 1259 OID 17949)
-- Name: payment; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.payment (
    id integer NOT NULL,
    cash real,
    mpesa real,
    cheque real,
    credit real,
    sales_id character varying(128) NOT NULL,
    deleted boolean DEFAULT false
);


ALTER TABLE public.payment OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 17947)
-- Name: payment_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.payment_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.payment_id_seq OWNER TO postgres;

--
-- TOC entry 3035 (class 0 OID 0)
-- Dependencies: 210
-- Name: payment_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.payment_id_seq OWNED BY public.payment.id;


--
-- TOC entry 207 (class 1259 OID 17913)
-- Name: priviledges; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.priviledges (
    id integer NOT NULL,
    username character varying(128) NOT NULL,
    can_add_user boolean DEFAULT true,
    can_remove_user boolean DEFAULT false,
    can_add_product boolean DEFAULT true,
    can_remove_product boolean DEFAULT false,
    can_add_stock boolean DEFAULT true,
    can_remove_sales boolean DEFAULT false,
    can_remove_stock boolean DEFAULT false,
    can_backup boolean DEFAULT false
);


ALTER TABLE public.priviledges OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 17911)
-- Name: priviledges_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.priviledges_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.priviledges_id_seq OWNER TO postgres;

--
-- TOC entry 3036 (class 0 OID 0)
-- Dependencies: 206
-- Name: priviledges_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.priviledges_id_seq OWNED BY public.priviledges.id;


--
-- TOC entry 199 (class 1259 OID 17847)
-- Name: product; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.product (
    id integer NOT NULL,
    barcode character varying(50) NOT NULL,
    product_name character varying(256) NOT NULL,
    product_unit character varying(36) NOT NULL,
    product_bp real DEFAULT 0,
    product_sp real DEFAULT 0,
    product_company character varying(128),
    type_id character varying(128) NOT NULL,
    product_deleted boolean DEFAULT false
);


ALTER TABLE public.product OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 17845)
-- Name: product_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.product_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.product_id_seq OWNER TO postgres;

--
-- TOC entry 3037 (class 0 OID 0)
-- Dependencies: 198
-- Name: product_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.product_id_seq OWNED BY public.product.id;


--
-- TOC entry 197 (class 1259 OID 17837)
-- Name: product_type; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.product_type (
    id integer NOT NULL,
    type_id character varying(64) NOT NULL,
    type_name character varying(128) NOT NULL
);


ALTER TABLE public.product_type OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 17835)
-- Name: product_type_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.product_type_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.product_type_id_seq OWNER TO postgres;

--
-- TOC entry 3038 (class 0 OID 0)
-- Dependencies: 196
-- Name: product_type_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.product_type_id_seq OWNED BY public.product_type.id;


--
-- TOC entry 213 (class 1259 OID 17960)
-- Name: sales; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.sales (
    id integer NOT NULL,
    sales_id character varying(128) NOT NULL,
    barcode character varying(50),
    sales_date timestamp without time zone NOT NULL,
    product_bp real NOT NULL,
    product_sp real NOT NULL,
    sale_qty integer NOT NULL,
    username character varying(128) NOT NULL,
    deleted boolean DEFAULT false
);


ALTER TABLE public.sales OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 17958)
-- Name: sales_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.sales_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.sales_id_seq OWNER TO postgres;

--
-- TOC entry 3039 (class 0 OID 0)
-- Dependencies: 212
-- Name: sales_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.sales_id_seq OWNED BY public.sales.id;


--
-- TOC entry 201 (class 1259 OID 17868)
-- Name: stock; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.stock (
    id integer NOT NULL,
    barcode character varying(50),
    stock_qty integer DEFAULT 0 NOT NULL,
    last_update timestamp with time zone NOT NULL
);


ALTER TABLE public.stock OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 17897)
-- Name: stock_history; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.stock_history (
    id integer NOT NULL,
    barcode character varying(50),
    stock_qty_before integer DEFAULT 0 NOT NULL,
    stock_qty_added integer DEFAULT 0 NOT NULL,
    date_updated timestamp with time zone NOT NULL,
    who_updated character varying(128) NOT NULL,
    is_adding boolean DEFAULT true
);


ALTER TABLE public.stock_history OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 17895)
-- Name: stock_history_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.stock_history_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.stock_history_id_seq OWNER TO postgres;

--
-- TOC entry 3040 (class 0 OID 0)
-- Dependencies: 204
-- Name: stock_history_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.stock_history_id_seq OWNED BY public.stock_history.id;


--
-- TOC entry 200 (class 1259 OID 17866)
-- Name: stock_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.stock_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.stock_id_seq OWNER TO postgres;

--
-- TOC entry 3041 (class 0 OID 0)
-- Dependencies: 200
-- Name: stock_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.stock_id_seq OWNED BY public.stock.id;


--
-- TOC entry 203 (class 1259 OID 17882)
-- Name: users; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.users (
    id integer NOT NULL,
    firstname character varying(128) NOT NULL,
    lastname character varying(128) NOT NULL,
    username character varying(128) NOT NULL,
    password character varying(128) NOT NULL,
    phone_no character varying(128) NOT NULL,
    date_added timestamp with time zone NOT NULL,
    to_change_password boolean DEFAULT false,
    to_delete_account boolean DEFAULT false
);


ALTER TABLE public.users OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 17880)
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.users_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO postgres;

--
-- TOC entry 3042 (class 0 OID 0)
-- Dependencies: 202
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- TOC entry 2807 (class 2604 OID 18002)
-- Name: credit id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit ALTER COLUMN id SET DEFAULT nextval('public.credit_id_seq'::regclass);


--
-- TOC entry 2808 (class 2604 OID 18023)
-- Name: credit_payments id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit_payments ALTER COLUMN id SET DEFAULT nextval('public.credit_payments_id_seq'::regclass);


--
-- TOC entry 2799 (class 2604 OID 17937)
-- Name: creditee id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.creditee ALTER COLUMN id SET DEFAULT nextval('public.creditee_id_seq'::regclass);


--
-- TOC entry 2809 (class 2604 OID 18039)
-- Name: login_history id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.login_history ALTER COLUMN id SET DEFAULT nextval('public.login_history_id_seq'::regclass);


--
-- TOC entry 2815 (class 2604 OID 18067)
-- Name: messages id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.messages ALTER COLUMN id SET DEFAULT nextval('public.messages_id_seq'::regclass);


--
-- TOC entry 2806 (class 2604 OID 17987)
-- Name: mpesa id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.mpesa ALTER COLUMN id SET DEFAULT nextval('public.mpesa_id_seq'::regclass);


--
-- TOC entry 2811 (class 2604 OID 18053)
-- Name: notifications id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.notifications ALTER COLUMN id SET DEFAULT nextval('public.notifications_id_seq'::regclass);


--
-- TOC entry 2802 (class 2604 OID 17952)
-- Name: payment id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.payment ALTER COLUMN id SET DEFAULT nextval('public.payment_id_seq'::regclass);


--
-- TOC entry 2790 (class 2604 OID 17916)
-- Name: priviledges id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.priviledges ALTER COLUMN id SET DEFAULT nextval('public.priviledges_id_seq'::regclass);


--
-- TOC entry 2777 (class 2604 OID 17850)
-- Name: product id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product ALTER COLUMN id SET DEFAULT nextval('public.product_id_seq'::regclass);


--
-- TOC entry 2776 (class 2604 OID 17840)
-- Name: product_type id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product_type ALTER COLUMN id SET DEFAULT nextval('public.product_type_id_seq'::regclass);


--
-- TOC entry 2804 (class 2604 OID 17963)
-- Name: sales id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sales ALTER COLUMN id SET DEFAULT nextval('public.sales_id_seq'::regclass);


--
-- TOC entry 2781 (class 2604 OID 17871)
-- Name: stock id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock ALTER COLUMN id SET DEFAULT nextval('public.stock_id_seq'::regclass);


--
-- TOC entry 2786 (class 2604 OID 17900)
-- Name: stock_history id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock_history ALTER COLUMN id SET DEFAULT nextval('public.stock_history_id_seq'::regclass);


--
-- TOC entry 2783 (class 2604 OID 17885)
-- Name: users id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- TOC entry 3013 (class 0 OID 17999)
-- Dependencies: 217
-- Data for Name: credit; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.credit (id, creditee_id, due_date, sales_id) VALUES (1, 46325326552, '2020-11-08 00:00:00', 'AS1604211061231');


--
-- TOC entry 3015 (class 0 OID 18020)
-- Dependencies: 219
-- Data for Name: credit_payments; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- TOC entry 3005 (class 0 OID 17934)
-- Dependencies: 209
-- Data for Name: creditee; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.creditee (id, firstname, lastname, national_id, phone_no, amount_due, date_added) VALUES (1, 'John', 'Doe', 46325326552, 8765443826, 1000, '2020-11-01 09:10:37+03');


--
-- TOC entry 3017 (class 0 OID 18036)
-- Dependencies: 221
-- Data for Name: login_history; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- TOC entry 3021 (class 0 OID 18064)
-- Dependencies: 225
-- Data for Name: messages; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- TOC entry 3011 (class 0 OID 17984)
-- Dependencies: 215
-- Data for Name: mpesa; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.mpesa (id, mpesa_id, sales_id) VALUES (1, 'MP1604211061328', 'AS1604211061231');


--
-- TOC entry 3019 (class 0 OID 18050)
-- Dependencies: 223
-- Data for Name: notifications; Type: TABLE DATA; Schema: public; Owner: postgres
--



--
-- TOC entry 3007 (class 0 OID 17949)
-- Dependencies: 211
-- Data for Name: payment; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.payment (id, cash, mpesa, cheque, credit, sales_id, deleted) VALUES (1, 1000, 1000, 1000, 1000, 'AS1604211061231', false);


--
-- TOC entry 3003 (class 0 OID 17913)
-- Dependencies: 207
-- Data for Name: priviledges; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.priviledges (id, username, can_add_user, can_remove_user, can_add_product, can_remove_product, can_add_stock, can_remove_sales, can_remove_stock, can_backup) VALUES (1, 'lalan', true, false, true, false, true, false, false, false);


--
-- TOC entry 2995 (class 0 OID 17847)
-- Dependencies: 199
-- Data for Name: product; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (1, '1600784535702', 'Syrenge', '20cc', 13, 20, 'BD Discardit', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (2, '1600784535712', 'Syrenge', '60cc', 45, 60, 'Sumbow', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (3, '1600784535722', 'Acteic Super', '1kg', 690, 800, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (4, '1600784535732', 'Actelic Super', '100g', 110, 130, 'twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (5, '1600784535742', 'Actelic Super', '200g', 190, 220, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (6, '1600784535752', 'Actelic Super', '500g', 390, 450, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (7, '1600784535763', 'Acteic Super', '50g', 80, 100, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (8, '1600784535773', 'Afya Bora Maziwa', '1kg', 160, 180, 'Unga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (9, '1600784535783', 'Afya Bora Maziwa', '2kg', 280, 320, 'Unga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (10, '1600784535793', 'Afya Bora Stocklick', '2kg', 95, 150, 'Unga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (11, '1600784535804', 'Agita', '20g', 145, 180, 'Novatis', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (12, '1600784535814', 'Alamycin Aerosol', '200ml', 320, 350, 'Norbrook', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (13, '1600784535824', 'Albafas 10%', '120ml', 110, 140, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (14, '1600784535834', 'Albafas 10%', '1 litre', 580, 650, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (15, '1600784535844', 'Albafas 10%', '40ml', 49, 70, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (16, '1600784535854', 'Albafas 10%', '500ml', 330, 370, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (17, '1600784535864', 'Albafas 2.5%', '500ml', 120, 180, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (18, '1600784535874', 'Albendazole 10%', '1 litre', 650, 700, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (19, '1600784535884', 'Albendazole 10%', '120ml', 140, 160, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (20, '1600784535894', 'Albendazole 10%', '250ml', 250, 300, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (21, '1600784535905', 'Albendazole 10%', '40ml', 50, 70, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (22, '1600784535915', 'Albendazole 10%', '500ml', 325, 420, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (23, '1600784535925', 'Albendazole Bolus', '300mg', 12, 20, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (24, '1600784535935', 'Albendazole Bolus', '600mg', 18, 30, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (25, '1600784535945', 'Albevet 10%', '1 litre', 550, 650, 'Medisel', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (26, '1600784535955', 'Albevet 10%', '500ml', 330, 380, 'Medisel', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (27, '1600784535965', 'Amilyte', '20g', 75, 100, 'Ultravetis', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (28, '1600784535976', 'Ascarex', '30g', 100, 120, 'Cosmos', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (29, '1600784535986', 'Ascaten P', '1 tablet', 12, 20, 'Cosmos', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (30, '1600784535996', 'Baraki bock', '25g', 45, 80, 'Highchem', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (31, '1600784536006', 'Bestphos maziwa', '1kg', 90, 150, 'Bestphos Ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (32, '1600784536017', 'Bestphos maziwa', '2 kg', 170, 250, 'Bestphos Ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (33, '1600784536027', 'Bestphos maziwa', '5kg', 380, 450, 'Bestphos Ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (34, '1600784536037', 'Bimectin', '50m', 180, 200, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (35, '1600784536047', 'Bisol', '25g', 75, 100, 'Vet care', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (36, '1600784536057', 'Biotrim vet', '30g', 87, 110, 'Biodeal', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (37, '1600784536068', 'Boma rhodes', '1kg', 850, 950, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (38, '1600784536078', 'Bupaquone', '20ml', 650, 750, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (39, '1600784536088', 'Bupaquone', '1ml', 22, 30, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (40, '1600784536099', 'Butasal100', '1ml', 18, 25, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (41, '1600784536109', 'Buvanol ', '1ml', 22.5, 30, 'Bimeda', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (42, '1600784536119', 'Buvanol ', '20ml', 480, 600, 'Bimeda', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (43, '1600784536129', 'Caciject', '400ml', 430, 500, 'Norbrook', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (44, '1600784536139', 'Calfoset', '100ml', 300, 350, 'Dawa Ltd', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (45, '1600784536150', 'Califonia wonder', '10g', 102, 150, 'Simlaw seeds', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (46, '1600784536160', 'Califonia wonder', '25g', 200, 240, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (47, '1600784536170', 'Califonia wonder', '50g', 460, 550, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (48, '1600784536180', 'Calj', '10g', 115, 150, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (49, '1600784536190', 'Calj', '25g', 217, 300, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (50, '1600784536200', 'Carrots ', '10g', 57, 80, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (51, '1600784536210', 'Carrots ', '25g', 104, 150, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (52, '1600784536220', 'Centrino', '25g', 85, 100, 'Cosmos', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (53, '1600784536230', 'Chick marsh', '20kg', 950, 1000, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (54, '1600784536240', 'Chick marsh', '70kg', 3500, 3800, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (55, '1600784536250', 'Chick marsh', '10kg', 650, 700, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (56, '1600784536261', 'Chick marsh', '1kg', 50, 60, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (57, '1600784536273', 'Chick start', '1sachet', 50, 70, 'Vet care', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (58, '1600784536283', 'CKL Xtra lick', '2kg', 330, 370, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (59, '1600784536293', 'CKL Xtra lick', '5kg', 762, 850, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (60, '1600784536303', 'Collards', '100g', 260, 330, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (61, '1600784536314', 'Collards', '10g', 49, 70, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (62, '1600784536324', 'Collards', '25g', 88, 120, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (63, '1600784536335', 'Collards', '250g', 533, 650, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (64, '1600784536345', 'Collards', '500g', 1027, 1200, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (65, '1600784536355', 'Collards', '50g', 138, 170, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (66, '1600784536365', 'Copenhagen', '100g', 211, 250, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (67, '1600784536375', 'Copenhagen', '10g', 36, 70, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (68, '1600784536385', 'Copenhagen', '25g', 68, 90, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (69, '1600784536395', 'Copenhagen', '50g', 125, 150, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (70, '1600784536405', 'Curafluke', '60ml', 140, 180, 'Bimeda', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (71, '1600784536415', 'D-Amine', '1 litre', 580, 650, 'Osho Co. Ltd', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (72, '1600784536425', 'D-Amine', '500ml', 330, 400, 'Osho Co. Ltd', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (73, '1600784536435', 'Dabotick', '20ml', 130, 150, 'True vets', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (74, '1600784536446', 'Dabotick', '40ML', 255, 280, 'True vets', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (75, '1600784536456', 'Dairy meal', '10kg', 250, 300, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (76, '1600784536466', 'Dairy meal', '20kg', 480, 550, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (77, '1600784536476', 'Dairy meal', '70kg', 1500, 1700, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (78, '1600784536486', 'DCP', '250g', 40, 80, 'Medisel', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (79, '1600784536496', 'DCP', '500g', 100, 120, 'Medisel', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (80, '1600784536506', 'DCP Ultraphos', '250g', 80, 100, 'Ultravetis', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (81, '1600784536516', 'DCP Ultraphos', '500g', 120, 150, 'Ultravetis', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (82, '1600784536529', 'Dehorning wire', '1 metre', 120, 150, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (83, '1600784536539', 'Delete', '20ml', 95, 120, 'Highchem', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (84, '1600784536549', 'Dexajet', '50ml', 180, 200, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (85, '1600784536559', 'Dexamethasone', '50ml', 180, 200, 'Eagles', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (86, '1600784536569', 'Diamond plant foliar', '1litre', 90, 120, 'Keapros', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (87, '1600784536579', 'Diamond plant foliar', '2litres', 120, 200, 'Keapros', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (88, '1600784536590', 'Diamond plant foliar', '500ml', 50, 80, 'Keapros', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (89, '1600784536600', 'Diazate', '28ml', 75, 90, '', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (90, '1600784536610', 'Diazol', '28ml', 95, 120, 'Amiran', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (91, '1600784536620', 'Dicopur', '500ml', 310, 370, '', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (92, '1600784536630', 'Diseptoprim pessaries', '1 tablet', 15, 20, 'Cosmos', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (93, '1600784536640', 'Duduthrin', '500ml', 600, 650, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (94, '1600784536650', 'Duduthrin', '100ml', 160, 180, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (95, '1600784536660', 'Duduthrin', '50ml', 110, 130, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (96, '1600784536671', 'Duduthrin', '200ml', 280, 320, 'Twiga', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (97, '1600784536681', 'Duodip', '100ml', 545, 600, 'Norbrook', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (98, '1600784536691', 'Duodip', '50ml', 315, 350, 'Norbrook', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (99, '1600784536701', 'Duodip', '20ml', 125, 150, 'Norbrook', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (100, '1600784536711', 'Duotech', '100ml', 300, 350, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (101, '1600784536721', 'Duotech', '500ml', 1400, 1600, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (102, '1600784536731', 'Duotech', '60ml', 165, 200, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (103, '1600784536741', 'Ear tags', '1 piece', 35, 50, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (104, '1600784536751', 'Easy grow fruit and flowering', '120g', 65, 80, 'Osho Co. Ltd', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (105, '1600784536762', 'Easy grow fruit and flowering', '250g', 95, 120, 'Osho Co. Ltd', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (106, '1600784536772', 'Easy grow vegetative', '120g', 65, 80, 'Osho Co. Ltd', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (107, '1600784536782', 'Easy grow vegetative', '250g', 95, 120, 'Osho Co. Ltd', '36569', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (108, '1600784536792', 'Egocin chick formula', '1 sachet', 50, 70, 'Cosmos', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (109, '1600784536803', 'Elmba rhodes', '1kg', 850, 950, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (110, '1600784536813', 'Endocure 10%', '40ml', 80, 100, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (111, '1600784536823', 'Endospec !0%', '1litre', 460, 600, '', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (112, '1600784536833', 'Endospec !0%', '500ml', 295, 380, '', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (113, '1600784536843', 'Endozole 2.5%', '1litre', 450, 500, '', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (114, '1600784536853', 'Epsom salt ', '500g', 100, 120, 'Medisel', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (115, '1600784536863', 'ESB3 30%', '20g', 220, 250, 'Ultravetis', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (116, '1600784536873', 'Famas dairy', '1kg', 110, 150, 'Light ventures ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (117, '1600784536884', 'Famas dairy', '2kg', 200, 250, 'Light ventures ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (118, '1600784536894', 'Famas dry cow', '1kg', 120, 180, 'Light ventures ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (119, '1600784536904', 'Famas joto', '1kg', 120, 170, 'Light ventures ltd', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (120, '1600784536914', 'fowl pox', '100ml', 500, 550, 'Medion', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (121, '1600784536924', 'Force 1 plus', '1litre', 790, 900, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (122, '1600784536934', 'Force 1 plus', '500ml', 460, 500, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (123, '1600784536944', 'Force 1 super', '125ml', 200, 220, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (124, '1600784536955', 'Force 1 super', '500ml', 550, 650, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (125, '1600784536965', 'Force 1 plus', '135ml', 135, 160, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (126, '1600784536975', 'Force 1 super', '1litre', 930, 950, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (127, '1600784536985', 'Fosbac plus T', '50g', 380, 450, 'Bupo animal health', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (128, '1600784536995', 'Fosbac plus T', '25g', 200, 250, 'Bupo animal health', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (129, '1600784537005', 'Fowl typhoid vaccine', '100 doses', 400, 500, 'Life technologies ltd', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (130, '1600784537016', 'Gardal', '40ml', 170, 200, 'Highchem', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (131, '1600784537026', 'Gloria', '10g', 568, 650, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (132, '1600784537036', 'Gloria', '25g', 1420, 1550, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (133, '1600784537046', 'Growers marsh', '1kg', 40, 50, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (134, '1600784537056', 'Gumboro', '100 doses', 220, 300, 'Indovax private ltd', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (135, '1600784537066', 'Gumboro', '200 doses', 350, 400, 'Indovax private ltd', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (136, '1600784537076', 'Heaing oil', '100ml', 180, 220, 'Coopers K Brand', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (137, '1600784537086', 'Herbikill', '1litre', 790, 900, 'Osho Co. Ltd', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (138, '1600784537097', 'Herbikill', '500ml', 530, 650, 'Osho Co. Ltd', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (139, '1600784537107', 'Hydrogen peroxide', '200ml', 45, 60, 'Palman Chemicals', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (140, '1600784537117', 'Insemination pippete', '1piece', 30, 40, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (141, '1600784537127', 'Ivermet', '50ml', 180, 200, 'Shanghai phamaceuticals', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (142, '1600784537137', 'Jackpot', '100ml', 265, 310, 'Coopers K Brand', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (143, '1600784537147', 'Jackpot', '200ml', 307, 360, 'Coopers K Brand', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (144, '1600784537157', 'Jackpot', '25ml', 99, 120, 'Coopers K Brand', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (145, '1600784537168', 'Jackpot', '50ml', 171, 200, 'Coopers K Brand', '35722', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (146, '1600784537178', 'Kienyeji marsh', '70kg', 2050, 2300, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (147, '1600784537188', 'Kienyeji marsh', '10kg', 400, 450, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (148, '1600784537198', 'Kienyeji marsh', '20kg', 700, 800, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (149, '1600784537208', 'Kienyeji marsh', '1kg', 29, 50, 'Turbo feeds', '36230', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (150, '1600784537218', 'Lanirat', '25g', 117, 150, 'Norvatis', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (151, '1600784537229', 'Levafas Xtra', '40ml', 90, 120, 'Norbrook', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (152, '1600784537239', 'Light kaolin', '100g', 35, 60, 'Medisel', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (153, '1600784537249', 'Light kaolin', '250g', 60, 100, 'Medisel', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (154, '1600784537259', 'Liquid parrafin', '100ml', 80, 100, 'Farmcare ltd', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (155, '1600784537270', 'Livotox', '100ml', 180, 220, '', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (156, '1600784537280', 'Lugols iodine', '120ml', 85, 110, 'Palman Chemicals', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (157, '1600784537290', 'Lugols iodine', '80ml', 60, 80, 'Palman Chemicals', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (158, '1600784537300', 'Maclik dry cow', '1kg', 180, 200, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (159, '1600784537310', 'Maclik mineral block', '2kg', 206, 250, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (160, '1600784537320', 'Maclik plus', '1kg', 130, 150, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (161, '1600784537330', 'Maclik plus', '2kg', 249, 290, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (162, '1600784537340', 'Maclik plus', '5kg', 575, 650, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (163, '1600784537351', 'maclik super', '1kg', 180, 200, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (164, '1600784537361', 'maclik super', '2kg', 340, 390, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (165, '1600784537371', 'maclik super', '5kg', 785, 920, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (166, '1600784537381', 'maclik super', '500g', 99, 120, 'Coopers K Brand', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (167, '1600784537391', 'Magadi ', '10kg', 180, 200, '', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (168, '1600784537401', 'Magic dairy', '1kg', 140, 160, 'Afrivet', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (169, '1600784537411', 'Metrocycline eye/wound powder', '25g', 90, 110, 'Hightech pharmaceuticas', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (170, '1600784537422', 'Milking Salve', '100g', 60, 80, 'Norbrook', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (171, '1600784537432', 'Milking Salve', '250g', 137, 170, 'Norbrook', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (172, '1600784537442', 'Milking Salve champion', '100g', 70, 80, 'Unga', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (173, '1600784537452', 'Milking Salve champion', '200g', 140, 180, 'Unga', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (174, '1600784537462', 'Milking salve', '100g', 72, 80, 'Coopers K Brand', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (175, '1600784537472', 'Milking salve', '250g', 154, 170, 'Coopers K Brand', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (176, '1600784537482', 'Milthane super', '100g', 95, 120, '', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (177, '1600784537493', 'Milthane super', '200g', 152, 200, '', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (178, '1600784537503', 'Milthane super', '500g', 332, 400, '', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (179, '1600784537513', 'Milthane super', '50g', 75, 90, '', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (180, '1600784537523', 'Multiboost', '100ml', 180, 200, 'Twiga', '37523', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (181, '1600784537533', 'Multiject IMM', '1piece', 75, 90, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (182, '1600784537543', 'Penikan P300', '1piece', 115, 150, 'Kela', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (183, '1600784537553', 'Multimed ', '1piece', 60, 90, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (184, '1600784537564', 'Multivitamin', '100ml', 180, 200, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (185, '1600784537574', 'NCD', '100Doses', 200, 300, 'Venkateshwara ', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (186, '1600784537584', 'NCD', '25doses', 100, 150, 'Life technologies ltd', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (187, '1600784537594', 'NCD', '50 Doses', 150, 220, 'Life technologies ltd', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (188, '1600784537604', 'NCD+IB', '200 doses', 300, 400, '', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (189, '1600784537614', 'Needle 18G', '1piece', 3.79999995, 5, 'Apha manufacturers', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (190, '1600784537624', 'Neocidol 600EW', '28ml', 75, 100, 'Ultravetis', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (191, '1600784537635', 'Nilzan bolus', '1piece', 77, 90, 'Coopers K Brand', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (192, '1600784537645', 'Nilzan plus', '1litre', 1300, 1450, 'Coopers K Brand', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (193, '1600784537655', 'Nilzan plus', '125ml', 194, 220, 'Coopers K Brand', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (194, '1600784537665', 'Nilzan plus', '150ml', 208, 240, 'Coopers K Brand', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (195, '1600784537675', 'Nilzan plus', '500ml', 725, 830, 'Coopers K Brand', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (196, '1600784537685', 'Norotraz', '100ml', 185, 220, 'Norbrook', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (197, '1600784537696', 'Norotraz', '40ml', 95, 120, 'Norbrook', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (198, '1600784537706', 'Norotryp', '2.3g sachet', 60, 100, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (199, '1600784537716', 'Opticlox syrenge', '5g', 110, 130, 'Norbrook', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (200, '1600784537726', 'Oshothane', '100g', 110, 130, 'Osho Co. Ltd', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (201, '1600784537736', 'Oshothane', '1kg', 565, 680, 'Osho Co. Ltd', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (202, '1600784537746', 'Oshothane', '200g', 170, 220, 'Osho Co. Ltd', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (203, '1600784537757', 'Oshothane', '500g', 385, 450, 'Osho Co. Ltd', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (204, '1600784537767', 'Oshothane', '50g', 80, 100, 'Osho Co. Ltd', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (205, '1600784537779', 'Oxymet ', '100ml', 160, 180, 'Metrovet', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (206, '1600784537789', 'Oxymet ', '250ml', 330, 370, 'Metrovet', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (207, '1600784537799', 'Parvexon', '1ml', 23.5, 30, 'Bimeda', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (208, '1600784537810', 'Parvon', '1ml', 18, 25, 'Bimeda', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (209, '1600784537820', 'Penistrep 20/20', '100ml', 380, 420, 'Medina chemicas', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (210, '1600784537830', 'Penstrep 400', '100ml', 360, 380, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (211, '1600784537840', 'Poltricin chick formula', '25g', 50, 80, 'Cosmos', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (212, '1600784537850', 'Promax 20 EC', '25ml', 125, 150, 'Highchem', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (213, '1600784537860', 'Rabisin', '1ml', 70, 100, 'Merial', '36914', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (214, '1600784537870', 'Rindomil gold', '250g', 690, 750, 'Syngenta', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (215, '1600784537880', 'Rindomil gold', '50g', 140, 160, 'Syngenta', '37482', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (216, '1600784537891', 'riogrande', '10g', 120, 150, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (217, '1600784537901', 'riogrande', '25g', 230, 300, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (218, '1600784537911', 'S-dime', '1bolus', 25, 30, 'Cosmos', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (219, '1600784537921', 'Sevin', '100g', 80, 100, 'Highchem', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (220, '1600784537931', 'Sevin', '200g', 125, 150, 'Highchem', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (221, '1600784537941', 'Sevin', '50g', 60, 80, 'Highchem', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (222, '1600784537951', 'Spinarch', '10g', 35, 50, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (223, '1600784537961', 'Spinarch', '25g', 62, 90, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (224, '1600784537972', 'Spinarch', '50g', 115, 150, 'Simlaw seeds', '36068', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (225, '1600784537982', 'Steadone', '100ml', 280, 320, 'Ultravetis', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (226, '1600784537992', 'Steadone', '35ml', 130, 150, 'Ultravetis', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (227, '1600784538002', 'Stopbloat', '120ml', 130, 170, 'Coopers K Brand', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (228, '1600784538012', 'Supermec', '50ml', 310, 370, '', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (229, '1600784538023', 'Surgical blade', '1piece', 5, 10, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (230, '1600784538033', 'Surgical surtures (non absobable)', '1piece', 60, 80, 'RT ED', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (231, '1600784538043', 'Surgical surtures (absobable)', '1piece', 80, 100, 'RT ED', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (232, '1600784538053', 'Terrexine', '10g', 190, 220, 'Univet', '35804', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (233, '1600784538063', 'Tetroxy', '100ml', 135, 160, 'Twiga', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (234, '1600784538074', 'Thermometer (clinical)', '1piece', 80, 100, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (235, '1600784538084', 'Thermometer (digital)', '1piece', 360, 400, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (236, '1600784538094', 'Triatix', '100ml', 249, 280, 'Coopers K Brand', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (237, '1600784538104', 'Triatix', '40ml', 115, 130, 'Coopers K Brand', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (238, '1600784538114', 'Triatix', '20ml', 82, 100, 'Coopers K Brand', '36435', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (239, '1600784538124', 'Tricure gold', '1litre', 850, 950, 'OAK medica', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (240, '1600784538134', 'Tricure gold', '500ml', 530, 600, 'OAK medica', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (241, '1600784538144', 'Tricure gold', '125ml', 190, 220, 'OAK medica', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (242, '1600784538155', 'Twigalick maziwa max', '1kg', 240, 300, 'Twiga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (243, '1600784538165', 'Twigalick maziwa max', '2kg', 320, 400, 'Twiga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (244, '1600784538175', 'twigalick maziwa zaidi', '1kg', 140, 180, 'Twiga', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (245, '1600784538185', 'Twigamec', '50ml', 175, 200, 'Twiga', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (246, '1600784538195', 'Twigamec', '100ml', 290, 350, 'Twiga', '36037', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (247, '1600784538205', 'Twigazle 10%', '500ml', 330, 380, 'Twiga', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (248, '1600784538216', 'Tylodoxy 200', '1 sachet', 125, 150, 'Alfa vets', '35965', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (249, '1600784538226', 'Ultramix maziwa', '1kg', 160, 180, 'Ultravetis', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (250, '1600784538236', 'Ultramix maziwa', '2kg', 300, 340, 'Ultravetis', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (251, '1600784538246', 'Valbazen 10%', '40ml', 220, 240, 'Ultravetis', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (252, '1600784538256', 'Valbazen 2.5%', '100ml', 195, 220, 'Ultravetis', '35824', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (253, '1600784538266', 'Vet glove', '1piece', 12, 20, '', '35702', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (254, '1600784538277', 'Vital joto', '1kg', 140, 170, 'Vital', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (255, '1600784538288', 'Vital joto', '2kg', 280, 320, 'Vital', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (256, '1600784538298', 'Vital maziwa', '1kg', 190, 220, 'Vital', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (257, '1600784538308', 'Vital maziwa', '2kg', 360, 400, 'Vital', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (258, '1600784538318', 'Vital ndama', '1kg', 145, 170, 'Vital', '35773', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (259, '1600784538328', 'Weedal', '1litre', 390, 450, 'Hanghzou agrochemicals', '36415', false);
INSERT INTO public.product (id, barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id, product_deleted) VALUES (260, '1600784538339', 'Weedal', '500ml', 260, 310, 'Hanghzou agrochemicals', '36415', false);


--
-- TOC entry 2993 (class 0 OID 17837)
-- Dependencies: 197
-- Data for Name: product_type; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.product_type (id, type_id, type_name) VALUES (1, '35702', 'Vet products');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (2, '35722', 'Pesticides');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (3, '35773', 'Mineral suppliments');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (4, '35804', 'Hygene products');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (5, '35824', 'Dewormer');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (6, '35965', 'Poultry products');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (7, '36037', 'Injectables');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (8, '36068', 'Seeds');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (9, '36230', 'Feeds');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (10, '36415', 'Herbicide');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (11, '36435', 'Accaricides');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (12, '36569', 'Fertilizers');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (13, '36914', 'Vaccine');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (14, '37482', 'Fungicides');
INSERT INTO public.product_type (id, type_id, type_name) VALUES (15, '37523', 'injectables');


--
-- TOC entry 3009 (class 0 OID 17960)
-- Dependencies: 213
-- Data for Name: sales; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.sales (id, sales_id, barcode, sales_date, product_bp, product_sp, sale_qty, username, deleted) VALUES (1, 'AS1604211061231', '1600784535722', '2020-11-01 09:11:01', 690, 800, 5, 'lalan', false);


--
-- TOC entry 2997 (class 0 OID 17868)
-- Dependencies: 201
-- Data for Name: stock; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (1, '1600784535702', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (2, '1600784535712', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (4, '1600784535732', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (5, '1600784535742', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (6, '1600784535752', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (7, '1600784535763', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (8, '1600784535773', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (9, '1600784535783', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (10, '1600784535793', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (11, '1600784535804', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (12, '1600784535814', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (13, '1600784535824', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (14, '1600784535834', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (15, '1600784535844', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (16, '1600784535854', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (17, '1600784535864', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (18, '1600784535874', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (19, '1600784535884', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (20, '1600784535894', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (21, '1600784535905', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (22, '1600784535915', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (23, '1600784535925', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (24, '1600784535935', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (25, '1600784535945', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (26, '1600784535955', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (27, '1600784535965', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (28, '1600784535976', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (29, '1600784535986', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (30, '1600784535996', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (31, '1600784536006', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (32, '1600784536017', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (33, '1600784536027', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (34, '1600784536037', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (35, '1600784536047', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (36, '1600784536057', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (37, '1600784536068', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (38, '1600784536078', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (39, '1600784536088', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (40, '1600784536099', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (41, '1600784536109', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (42, '1600784536119', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (43, '1600784536129', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (44, '1600784536139', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (45, '1600784536150', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (46, '1600784536160', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (47, '1600784536170', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (48, '1600784536180', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (49, '1600784536190', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (50, '1600784536200', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (51, '1600784536210', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (52, '1600784536220', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (53, '1600784536230', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (54, '1600784536240', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (55, '1600784536250', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (56, '1600784536261', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (57, '1600784536273', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (58, '1600784536283', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (59, '1600784536293', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (60, '1600784536303', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (61, '1600784536314', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (62, '1600784536324', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (63, '1600784536335', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (64, '1600784536345', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (65, '1600784536355', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (66, '1600784536365', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (67, '1600784536375', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (68, '1600784536385', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (69, '1600784536395', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (70, '1600784536405', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (71, '1600784536415', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (72, '1600784536425', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (73, '1600784536435', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (74, '1600784536446', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (75, '1600784536456', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (76, '1600784536466', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (77, '1600784536476', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (78, '1600784536486', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (79, '1600784536496', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (80, '1600784536506', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (81, '1600784536516', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (82, '1600784536529', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (83, '1600784536539', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (84, '1600784536549', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (85, '1600784536559', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (86, '1600784536569', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (87, '1600784536579', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (88, '1600784536590', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (89, '1600784536600', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (90, '1600784536610', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (91, '1600784536620', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (92, '1600784536630', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (93, '1600784536640', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (94, '1600784536650', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (95, '1600784536660', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (96, '1600784536671', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (97, '1600784536681', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (98, '1600784536691', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (99, '1600784536701', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (100, '1600784536711', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (101, '1600784536721', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (102, '1600784536731', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (103, '1600784536741', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (104, '1600784536751', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (105, '1600784536762', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (106, '1600784536772', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (107, '1600784536782', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (108, '1600784536792', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (109, '1600784536803', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (110, '1600784536813', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (111, '1600784536823', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (112, '1600784536833', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (113, '1600784536843', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (114, '1600784536853', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (115, '1600784536863', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (116, '1600784536873', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (117, '1600784536884', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (118, '1600784536894', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (119, '1600784536904', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (120, '1600784536914', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (121, '1600784536924', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (122, '1600784536934', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (123, '1600784536944', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (124, '1600784536955', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (125, '1600784536965', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (126, '1600784536975', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (127, '1600784536985', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (128, '1600784536995', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (129, '1600784537005', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (130, '1600784537016', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (131, '1600784537026', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (132, '1600784537036', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (133, '1600784537046', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (134, '1600784537056', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (135, '1600784537066', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (136, '1600784537076', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (137, '1600784537086', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (138, '1600784537097', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (139, '1600784537107', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (140, '1600784537117', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (141, '1600784537127', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (142, '1600784537137', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (143, '1600784537147', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (144, '1600784537157', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (145, '1600784537168', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (146, '1600784537178', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (147, '1600784537188', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (148, '1600784537198', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (149, '1600784537208', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (150, '1600784537218', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (151, '1600784537229', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (152, '1600784537239', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (153, '1600784537249', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (154, '1600784537259', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (155, '1600784537270', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (156, '1600784537280', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (157, '1600784537290', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (158, '1600784537300', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (159, '1600784537310', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (160, '1600784537320', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (161, '1600784537330', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (162, '1600784537340', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (163, '1600784537351', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (164, '1600784537361', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (165, '1600784537371', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (166, '1600784537381', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (167, '1600784537391', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (168, '1600784537401', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (169, '1600784537411', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (170, '1600784537422', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (171, '1600784537432', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (172, '1600784537442', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (173, '1600784537452', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (174, '1600784537462', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (175, '1600784537472', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (176, '1600784537482', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (177, '1600784537493', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (178, '1600784537503', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (179, '1600784537513', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (180, '1600784537523', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (181, '1600784537533', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (182, '1600784537543', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (183, '1600784537553', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (184, '1600784537564', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (185, '1600784537574', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (186, '1600784537584', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (187, '1600784537594', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (188, '1600784537604', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (189, '1600784537614', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (190, '1600784537624', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (191, '1600784537635', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (192, '1600784537645', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (193, '1600784537655', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (194, '1600784537665', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (195, '1600784537675', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (196, '1600784537685', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (197, '1600784537696', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (198, '1600784537706', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (199, '1600784537716', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (200, '1600784537726', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (201, '1600784537736', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (202, '1600784537746', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (203, '1600784537757', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (204, '1600784537767', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (205, '1600784537779', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (206, '1600784537789', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (207, '1600784537799', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (208, '1600784537810', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (209, '1600784537820', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (210, '1600784537830', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (211, '1600784537840', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (212, '1600784537850', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (213, '1600784537860', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (214, '1600784537870', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (215, '1600784537880', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (216, '1600784537891', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (217, '1600784537901', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (218, '1600784537911', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (219, '1600784537921', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (220, '1600784537931', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (221, '1600784537941', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (222, '1600784537951', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (223, '1600784537961', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (224, '1600784537972', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (225, '1600784537982', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (226, '1600784537992', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (227, '1600784538002', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (228, '1600784538012', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (229, '1600784538023', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (230, '1600784538033', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (231, '1600784538043', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (232, '1600784538053', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (233, '1600784538063', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (234, '1600784538074', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (235, '1600784538084', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (236, '1600784538094', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (237, '1600784538104', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (238, '1600784538114', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (239, '1600784538124', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (240, '1600784538134', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (241, '1600784538144', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (242, '1600784538155', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (243, '1600784538165', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (244, '1600784538175', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (245, '1600784538185', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (246, '1600784538195', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (247, '1600784538205', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (248, '1600784538216', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (249, '1600784538226', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (250, '1600784538236', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (251, '1600784538246', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (252, '1600784538256', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (253, '1600784538266', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (254, '1600784538277', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (255, '1600784538288', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (256, '1600784538298', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (257, '1600784538308', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (258, '1600784538318', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (259, '1600784538328', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (260, '1600784538339', 0, '2020-09-22 18:28:56+03');
INSERT INTO public.stock (id, barcode, stock_qty, last_update) VALUES (3, '1600784535722', 0, '2020-11-01 09:09:04+03');


--
-- TOC entry 3001 (class 0 OID 17897)
-- Dependencies: 205
-- Data for Name: stock_history; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.stock_history (id, barcode, stock_qty_before, stock_qty_added, date_updated, who_updated, is_adding) VALUES (1, '1600784535722', 0, 5, '2020-11-01 09:09:04+03', 'lalan', true);


--
-- TOC entry 2999 (class 0 OID 17882)
-- Dependencies: 203
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.users (id, firstname, lastname, username, password, phone_no, date_added, to_change_password, to_delete_account) VALUES (1, 'Allan', 'Koech', 'lalan', '6d2d5deec0e24539fbe018e5ce62fb1736cdf05ccfa0da81f109de30e8cfd445:1603203145', '0703337925', '2020-10-20 17:12:25+03', false, false);


--
-- TOC entry 3043 (class 0 OID 0)
-- Dependencies: 216
-- Name: credit_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.credit_id_seq', 1, true);


--
-- TOC entry 3044 (class 0 OID 0)
-- Dependencies: 218
-- Name: credit_payments_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.credit_payments_id_seq', 1, false);


--
-- TOC entry 3045 (class 0 OID 0)
-- Dependencies: 208
-- Name: creditee_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.creditee_id_seq', 1, true);


--
-- TOC entry 3046 (class 0 OID 0)
-- Dependencies: 220
-- Name: login_history_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.login_history_id_seq', 1, false);


--
-- TOC entry 3047 (class 0 OID 0)
-- Dependencies: 224
-- Name: messages_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.messages_id_seq', 1, false);


--
-- TOC entry 3048 (class 0 OID 0)
-- Dependencies: 214
-- Name: mpesa_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.mpesa_id_seq', 1, true);


--
-- TOC entry 3049 (class 0 OID 0)
-- Dependencies: 222
-- Name: notifications_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.notifications_id_seq', 1, false);


--
-- TOC entry 3050 (class 0 OID 0)
-- Dependencies: 210
-- Name: payment_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.payment_id_seq', 1, true);


--
-- TOC entry 3051 (class 0 OID 0)
-- Dependencies: 206
-- Name: priviledges_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.priviledges_id_seq', 1, true);


--
-- TOC entry 3052 (class 0 OID 0)
-- Dependencies: 198
-- Name: product_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.product_id_seq', 260, true);


--
-- TOC entry 3053 (class 0 OID 0)
-- Dependencies: 196
-- Name: product_type_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.product_type_id_seq', 15, true);


--
-- TOC entry 3054 (class 0 OID 0)
-- Dependencies: 212
-- Name: sales_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.sales_id_seq', 1, true);


--
-- TOC entry 3055 (class 0 OID 0)
-- Dependencies: 204
-- Name: stock_history_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.stock_history_id_seq', 1, true);


--
-- TOC entry 3056 (class 0 OID 0)
-- Dependencies: 200
-- Name: stock_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.stock_id_seq', 260, true);


--
-- TOC entry 3057 (class 0 OID 0)
-- Dependencies: 202
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.users_id_seq', 1, true);


--
-- TOC entry 2852 (class 2606 OID 18028)
-- Name: credit_payments credit_payments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit_payments
    ADD CONSTRAINT credit_payments_pkey PRIMARY KEY (id);


--
-- TOC entry 2850 (class 2606 OID 18007)
-- Name: credit credit_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit
    ADD CONSTRAINT credit_pkey PRIMARY KEY (id);


--
-- TOC entry 2836 (class 2606 OID 17946)
-- Name: creditee creditee_national_id_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.creditee
    ADD CONSTRAINT creditee_national_id_key UNIQUE (national_id);


--
-- TOC entry 2838 (class 2606 OID 17944)
-- Name: creditee creditee_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.creditee
    ADD CONSTRAINT creditee_pkey PRIMARY KEY (id);


--
-- TOC entry 2854 (class 2606 OID 18042)
-- Name: login_history login_history_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.login_history
    ADD CONSTRAINT login_history_pkey PRIMARY KEY (id);


--
-- TOC entry 2858 (class 2606 OID 18073)
-- Name: messages messages_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.messages
    ADD CONSTRAINT messages_pkey PRIMARY KEY (id);


--
-- TOC entry 2846 (class 2606 OID 17991)
-- Name: mpesa mpesa_mpesa_id_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.mpesa
    ADD CONSTRAINT mpesa_mpesa_id_key UNIQUE (mpesa_id);


--
-- TOC entry 2848 (class 2606 OID 17989)
-- Name: mpesa mpesa_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.mpesa
    ADD CONSTRAINT mpesa_pkey PRIMARY KEY (id);


--
-- TOC entry 2856 (class 2606 OID 18061)
-- Name: notifications notifications_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.notifications
    ADD CONSTRAINT notifications_pkey PRIMARY KEY (id);


--
-- TOC entry 2840 (class 2606 OID 17955)
-- Name: payment payment_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.payment
    ADD CONSTRAINT payment_pkey PRIMARY KEY (id);


--
-- TOC entry 2842 (class 2606 OID 17957)
-- Name: payment payment_sales_id_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.payment
    ADD CONSTRAINT payment_sales_id_key UNIQUE (sales_id);


--
-- TOC entry 2834 (class 2606 OID 17926)
-- Name: priviledges priviledges_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.priviledges
    ADD CONSTRAINT priviledges_pkey PRIMARY KEY (id);


--
-- TOC entry 2822 (class 2606 OID 17860)
-- Name: product product_barcode_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_barcode_key UNIQUE (barcode);


--
-- TOC entry 2824 (class 2606 OID 17858)
-- Name: product product_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_pkey PRIMARY KEY (id);


--
-- TOC entry 2818 (class 2606 OID 17842)
-- Name: product_type product_type_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product_type
    ADD CONSTRAINT product_type_pkey PRIMARY KEY (id);


--
-- TOC entry 2820 (class 2606 OID 17844)
-- Name: product_type product_type_type_id_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product_type
    ADD CONSTRAINT product_type_type_id_key UNIQUE (type_id);


--
-- TOC entry 2844 (class 2606 OID 17966)
-- Name: sales sales_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sales
    ADD CONSTRAINT sales_pkey PRIMARY KEY (id);


--
-- TOC entry 2832 (class 2606 OID 17905)
-- Name: stock_history stock_history_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock_history
    ADD CONSTRAINT stock_history_pkey PRIMARY KEY (id);


--
-- TOC entry 2826 (class 2606 OID 17874)
-- Name: stock stock_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock
    ADD CONSTRAINT stock_pkey PRIMARY KEY (id);


--
-- TOC entry 2828 (class 2606 OID 17892)
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- TOC entry 2830 (class 2606 OID 17894)
-- Name: users users_username_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_username_key UNIQUE (username);


--
-- TOC entry 2867 (class 2606 OID 18008)
-- Name: credit credit_creditee_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit
    ADD CONSTRAINT credit_creditee_id_fkey FOREIGN KEY (creditee_id) REFERENCES public.creditee(national_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2869 (class 2606 OID 18029)
-- Name: credit_payments credit_payments_creditee_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit_payments
    ADD CONSTRAINT credit_payments_creditee_id_fkey FOREIGN KEY (creditee_id) REFERENCES public.creditee(national_id) ON UPDATE CASCADE ON DELETE SET NULL;


--
-- TOC entry 2868 (class 2606 OID 18013)
-- Name: credit credit_sales_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.credit
    ADD CONSTRAINT credit_sales_id_fkey FOREIGN KEY (sales_id) REFERENCES public.payment(sales_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2870 (class 2606 OID 18043)
-- Name: login_history login_history_username_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.login_history
    ADD CONSTRAINT login_history_username_fkey FOREIGN KEY (username) REFERENCES public.users(username) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2866 (class 2606 OID 17992)
-- Name: mpesa mpesa_sales_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.mpesa
    ADD CONSTRAINT mpesa_sales_id_fkey FOREIGN KEY (sales_id) REFERENCES public.payment(sales_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2862 (class 2606 OID 17927)
-- Name: priviledges priviledges_username_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.priviledges
    ADD CONSTRAINT priviledges_username_fkey FOREIGN KEY (username) REFERENCES public.users(username) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2859 (class 2606 OID 17861)
-- Name: product product_type_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_type_id_fkey FOREIGN KEY (type_id) REFERENCES public.product_type(type_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2865 (class 2606 OID 17977)
-- Name: sales sales_barcode_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sales
    ADD CONSTRAINT sales_barcode_fkey FOREIGN KEY (barcode) REFERENCES public.product(barcode) ON UPDATE CASCADE ON DELETE SET NULL;


--
-- TOC entry 2863 (class 2606 OID 17967)
-- Name: sales sales_sales_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sales
    ADD CONSTRAINT sales_sales_id_fkey FOREIGN KEY (sales_id) REFERENCES public.payment(sales_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2864 (class 2606 OID 17972)
-- Name: sales sales_username_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.sales
    ADD CONSTRAINT sales_username_fkey FOREIGN KEY (username) REFERENCES public.users(username) ON UPDATE CASCADE ON DELETE SET NULL;


--
-- TOC entry 2860 (class 2606 OID 17875)
-- Name: stock stock_barcode_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock
    ADD CONSTRAINT stock_barcode_fkey FOREIGN KEY (barcode) REFERENCES public.product(barcode) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2861 (class 2606 OID 17906)
-- Name: stock_history stock_history_who_updated_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.stock_history
    ADD CONSTRAINT stock_history_who_updated_fkey FOREIGN KEY (who_updated) REFERENCES public.users(username) ON UPDATE CASCADE ON DELETE SET NULL;


-- Completed on 2020-12-28 13:52:41

--
-- PostgreSQL database dump complete
--

