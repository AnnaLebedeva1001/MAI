USE Lebedeva_310;
/*������� ������������, ������� ���������� ������ ������ ��������
�� ���������� ����� ���� ������������*/

SELECT name_airline AS '������������', AVG(Flight.airline_id) AS '������� ���������� ������',
COUNT(Flight.airline_id) AS '���������� ������'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline
HAVING COUNT(Flight.airline_id) > (SELECT AVG(Flight.airline_id))