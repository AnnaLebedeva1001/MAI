CREATE TABLE Airlines(
	airline_id INT IDENTITY(1,1) PRIMARY KEY,
	airline_name VARCHAR(50)
	);

CREATE TABLE Aircrafts(
	aircraft_id INT IDENTITY(1,1) PRIMARY KEY,
	aircraft_name VARCHAR(50)
	);

CREATE TABLE Aircraft_routes(
	route_id INT IDENTITY(1,1) PRIMARY KEY,
	route_length FLOAT,
	name_city_departure VARCHAR(50),
	name_city_arrival VARCHAR(50),
	date_dispatch DATETIME2,
	date_arrival DATETIME2
	);