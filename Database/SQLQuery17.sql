USE Lebedeva_310;

GO
CREATE VIEW flights_10 AS SELECT ticket_price, date_time_arrival, date_time_departure
FROM Flight
WHERE ticket_price >= 4000;

GO
INSERT INTO flights_10
    VALUES (4000, '2021-10-11 17:35', '2021-10-11 20:05');

SELECT * FROM flights_10;