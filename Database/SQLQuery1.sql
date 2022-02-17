USE Lebedeva_310;

CREATE TABLE Airline(
 airline_id INT IDENTITY(1, 1) PRIMARY KEY,
 name_airline VARCHAR(50)
 )

CREATE TABLE Route(
 route_id INT IDENTITY(1, 1) PRIMARY KEY,
 distance FLOAT,
 departure_city VARCHAR(50),
 arrival_city VARCHAR(50)
 )

CREATE TABLE Plane(
 plane_id INT IDENTITY(1, 1) PRIMARY KEY,
 name_plane VARCHAR(50),
 number_of_seats INT
 )

CREATE TABLE Flight(
 flight_id INT IDENTITY(1, 1) PRIMARY KEY,
 airline_id INT,
 plane_id INT,
 route_id INT,
 ticket_price FLOAT,
 date_time_departure DATETIME2,
 date_time_arrival DATETIME2,
 FOREIGN KEY (airline_id)  REFERENCES Airline (airline_id) ON DELETE CASCADE,
 FOREIGN KEY (route_id)  REFERENCES Route (route_id) ON DELETE CASCADE
 )

CREATE TABLE Plane_Flight(
    plane_id INT FOREIGN KEY REFERENCES Plane(plane_id),
	flight_id INT FOREIGN KEY REFERENCES Flight(flight_id),
	PRIMARY KEY(plane_id, flight_id)
 )
