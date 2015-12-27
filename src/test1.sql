
CREATE DATABASE orderDB;
USE orderDB;

CREATE TABLE customer (
  id int(10) NOT NULL,
  name varchar(25) NOT NULL,
  gender varchar(1),
  PRIMARY KEY  (id),
  CHECK (gender in('F','M'))
);

INSERT INTO customer VALUES
 (300001,'CHAD CABELLO','F'),
 (300002,'FAUSTO VANNORMAN','F'),
 (300003,'JO CANNADY','M'),
 (300004,'LAWERENCE MOTE','F'),
 (300005,'RODERICK NEVES','F'),
 (300006,'JACOB LEDGER','M'),
 (300007,'WALKER JOLIN','M'),
 (300008,'SELINA TAULBEE','F');

SHOW DATABASE orderDB;
SHOW TABLE customer;

update customer set id = 300006 where name = 'WALKER JOLIN';
DELETE FROM customer WHERE name='SELINA TAULBEE';
SELECT * FROM customer;
SELECT * FROM customer WHERE id > 300004;
SELECT * FROM customer WHERE id < 300004;
SELECT * FROM customer WHERE id = 300004;
SELECT id FROM customer WHERE name='CHAD CABELLO' OR gender = 'M';
SELECT customer.id FROM customer WHERE customer.gender = 'F';
SELECT SUM(customer.id) FROM customer WHERE customer.gender = 'F';
SELECT AVG(customer.id) FROM customer WHERE customer.gender = 'F';
SELECT MAX(customer.id) FROM customer WHERE customer.gender = 'F';
SELECT MIN(customer.id) FROM customer WHERE customer.gender = 'F';
SELECT gender,SUM(id) FROM customer GROUP BY gender; 

INSERT INTO customer VALUES
 (300009,'SELINA TAULBEE1',null);
SELECT * FROM customer WHERE name like '%SELINA%';
SELECT * FROM customer WHERE gender is null;

CREATE TABLE orders (
  customer_id int(10) NOT NULL,
  quantity int(10) NOT NULL
);

INSERT into orders values 
(300001,2);

SELECT * FROM orders;

update orders set customer_id = 1 where customer_id = 300001;

