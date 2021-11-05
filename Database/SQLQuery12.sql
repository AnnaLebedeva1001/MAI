USE Lebedeva_310;

SELECT flight_id, airline_id, ticket_price
      FROM Flights WHERE ticket_price IN (999, 2400);

SELECT route_id, route_length, name_city_departure, name_city_arrival
      FROM Aircraft_routes WHERE route_length IN (2000, 3000);

SELECT flight_id, airline_id
      FROM Flights WHERE aircraft_id IN (3, 4);