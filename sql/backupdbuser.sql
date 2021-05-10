CREATE ROLE backupdb WITH LOGIN PASSWORD '<password>' 
NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE NOREPLICATION VALID UNTIL 'infinity';
GRANT CONNECT ON DATABASE salama TO backupdb;
GRANT USAGE ON SCHEMA public TO backupdb;
GRANT SELECT ON ALL TABLES IN SCHEMA public TO backupdb;
GRANT SELECT ON ALL SEQUENCES IN SCHEMA public TO backupdb;
ALTER DEFAULT PRIVILEGES IN SCHEMA public GRANT SELECT ON TABLES TO backupdb;

-- export PGPASSWORD=<password>
-- /etc/postgresql/xx/main/pg_hba.conf -- add user backupdb
-- service postgresql restart