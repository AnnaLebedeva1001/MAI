USE Lebedeva_310;

SELECT flight_id, airline_id, ticket_price
      FROM Flights WHERE ticket_price BETWEEN 1000 AND 4000;

SELECT route_id, route_length
      FROM Aircraft_routes WHERE route_length BETWEEN 500 AND 1000;

SELECT flight_id, airline_id, date_time_dispath, date_time_arrival
      FROM Flights WHERE date_time_arrival BETWEEN '2021-11-11 00:00:00.000' AND '2021-11-12 00:00:00.000';