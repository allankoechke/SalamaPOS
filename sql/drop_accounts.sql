UPDATE sales SET username='Alice' WHERE username='Koech' OR username='Alfred' OR username='Admin' OR username='ALFRED';
UPDATE stock_history SET who_updated='Alice' WHERE who_updated='Koech' OR who_updated='Alfred' OR who_updated='Admin' OR who_updated='ALFRED';
DELETE FROM users WHERE username='Koech';
DELETE FROM users WHERE username='Alfred';
DELETE FROM users WHERE username='Admin';
DELETE FROM users WHERE username='ALFRED';