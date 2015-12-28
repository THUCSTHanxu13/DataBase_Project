
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
update customer set id = id + 1 where id = 300008;
SELECT * FROM customer;

