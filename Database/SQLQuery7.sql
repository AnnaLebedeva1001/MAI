CREATE TABLE Flights(
		flight_id INT IDENTITY(1,1) PRIMARY KEY,
		airline_id INT NOT NULL,
		aircraft_id INT NOT NULL,
		ticket_price FLOAT,
		route_id INT NOT NULL,
		date_time_dispath DATETIME,
		date_time_arrival DATETIME,
		FOREIGN KEY (airline_id)  REFERENCES Airlines (airline_id) ON DELETE CASCADE,
		FOREIGN KEY (aircraft_id)  REFERENCES Aircrafts (aircraft_id) ON DELETE CASCADE,
		FOREIGN KEY (route_id)  REFERENCES Aircraft_routes (route_id) ON DELETE CASCADE
		);