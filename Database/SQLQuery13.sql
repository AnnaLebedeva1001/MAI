USE Lebedeva_310;
/*Уменьшить цену билета на рейс на 20 рублей для тех авиакомпаний,
которые имеют более 10 самолетов*/

UPDATE Flight
SET ticket_price = ticket_price - 10
WHERE EXISTS(SELECT name_airline, COUNT(Plane_Flight.plane_id)
FROM Flight, Plane_Flight, Airline
WHERE Airline.airline_id = Flight.airline_id AND Flight.flight_id = Plane_Flight.flight_id
GROUP BY name_airline
HAVING COUNT(Plane_Flight.plane_id) > 10);