USE Drugstore;

CREATE TABLE Addresses(
id_address INT IDENTITY(1, 1) PRIMARY KEY,
country VARCHAR(25),
city VARCHAR(25),
street VARCHAR(25),
house INT
);

CREATE TABLE Telephones(
id_telephone INT IDENTITY(1, 1) PRIMARY KEY,
telephone BIGINT
);

CREATE TABLE Suppliers(
id_supplier INT IDENTITY(1, 1) PRIMARY KEY,
name VARCHAR(25),
id_address INT,
id_telephone INT,
FOREIGN KEY (id_address)  REFERENCES Addresses (id_address) ON DELETE CASCADE,
FOREIGN KEY (id_telephone)  REFERENCES Telephones (id_telephone) ON DELETE CASCADE,
);

CREATE TABLE Drug_prescriptions(
id_drug_prescription INT IDENTITY(1, 1) PRIMARY KEY,
drug_category VARCHAR(20),
description VARCHAR(255)
);

CREATE TABLE Drugs(
id_drug INT IDENTITY(1, 1) PRIMARY KEY,
name_drug VARCHAR(30),
id_drug_prescription INT,
count_drug INT,
selling_price FLOAT,
FOREIGN KEY (id_drug_prescription)  REFERENCES Drug_prescriptions (id_drug_prescription) ON DELETE CASCADE
);

CREATE TABLE Positions(
id_position INT IDENTITY(1, 1) PRIMARY KEY,
position_name VARCHAR(25)
);

CREATE TABLE Employees(
id_employee INT IDENTITY(1, 1) PRIMARY KEY,
full_name VARCHAR(50),
id_position INT,
date_of_birth DATE,
date_of_adoption DATE,
id_address INT,
id_telephone INT,
FOREIGN KEY (id_address)  REFERENCES Addresses (id_address) ON DELETE CASCADE,
FOREIGN KEY (id_telephone)  REFERENCES Telephones (id_telephone) ON DELETE CASCADE,
FOREIGN KEY (id_position)  REFERENCES Positions (id_position) ON DELETE CASCADE
);

CREATE TABLE Clients(
id_client INT IDENTITY(1, 1) PRIMARY KEY,
full_name VARCHAR(50),
date_of_birth DATE
);

CREATE TABLE Sale(
id_sale INT IDENTITY(1, 1) PRIMARY KEY,
id_drug INT,
count_sale INT,
id_employee INT,
date_and_time_of_sale DATETIME2,
id_client INT,
FOREIGN KEY (id_drug)  REFERENCES Drugs (id_drug) ON DELETE CASCADE,
FOREIGN KEY (id_employee)  REFERENCES Employees (id_employee) ON DELETE CASCADE,
FOREIGN KEY (id_client)  REFERENCES Clients (id_client) ON DELETE CASCADE
);


CREATE TABLE Illness(
id_illness INT IDENTITY(1, 1) PRIMARY KEY,
name_illness VARCHAR(25),
description VARCHAR(255)
);

CREATE TABLE Therapy(
id_illness INT FOREIGN KEY REFERENCES Illness(id_illness),
id_drug_prescription INT FOREIGN KEY REFERENCES Drug_prescriptions(id_drug_prescription),
PRIMARY KEY(id_illness, id_drug_prescription)
);

CREATE TABLE Supply(
date_of_supply DATE,
id_drug INT,
count_drug INT,
id_supplier INT,
purchase_price FLOAT,
FOREIGN KEY (id_supplier)  REFERENCES Suppliers (id_supplier) ON DELETE CASCADE,
FOREIGN KEY (id_drug)  REFERENCES Drugs (id_drug) ON DELETE CASCADE,
PRIMARY KEY (id_drug, id_supplier)
);