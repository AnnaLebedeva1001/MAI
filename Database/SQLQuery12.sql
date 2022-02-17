USE Lebedeva_310;
/*���������� ��������, �� ������� ����������� ����� ��� 5 ������*/

SELECT Route.route_id, Route.departure_city, Route.arrival_city, COUNT(Flight.route_id) AS '���������� ������ ��� ��������'
FROM Flight, Route
WHERE Flight.route_id = Route.route_id
GROUP BY Route.route_id, Route.departure_city, Route.arrival_city
HAVING (SELECT COUNT(Flight.route_id)) > 5;