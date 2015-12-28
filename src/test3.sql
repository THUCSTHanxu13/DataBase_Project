USE orderDB;

SELECT title FROM book WHERE authors IS NULL;
SELECT * FROM publisher WHERE state='CA';
SELECT book.title, orders.quantity FROM book, orders WHERE book.id=orders.book_id AND orders.quantity>8;


