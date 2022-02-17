USE Lebedeva_310;
/*���������� ������� ����� ��������� ��� ������ ������������*/

SELECT Airline.airline_id, name_airline AS '������������', AVG(Route.distance) AS '������� ����� ��������� ��� ������ ������������'
FROM Flight, Airline, Route
WHERE Flight.airline_id = Airline.airline_id AND Flight.route_id = Route.route_id
GROUP BY name_airline, Airline.airline_id;