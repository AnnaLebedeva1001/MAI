USE Lebedeva_310;

SELECT airline_id, ticket_price
      FROM Flights WHERE ticket_price > 2000;

SELECT flight_id, ticket_price, date_time_arrival, date_time_dispath
	FROM Flights WHERE ticket_price <= 5000 AND ticket_price >= 3000;

SELECT route_length, name_city_arrival, name_city_departure
      FROM Aircraft_routes WHERE name_city_departure <> 'Москва';