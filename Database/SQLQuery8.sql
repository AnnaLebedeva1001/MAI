USE Lebedeva_310;
/*��� ������ ������������ ���������� ���������� ���������, ��
������� ����������� ������*/
SELECT Airline.airline_id, name_airline AS '������������', COUNT(DISTINCT route_id) AS '���������� ��������� ��� ������ ������������, �� ������� ����������� ������'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline, Airline.airline_id;