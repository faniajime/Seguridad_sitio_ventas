

CREATE TABLE usuario (
	nombre varchar(255) NOT NULL,
	usuario varchar(255) NOT NULL PRIMARY KEY,
	email varchar(255) NOT NULL,
	telefono int(8) NOT NULL,
	contrasena varchar(255) NOT NULL, 
	direccion varchar(255) NOT NULL
);


CREATE TABLE preguntas(
	id INT NOT NULL AUTO_INCREMENT, 
	usuario varchar(255),
	pregunta varchar(255) NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (usuario) references usuario(usuario)
	ON DELETE CASCADE
	ON UPDATE CASCADE
);

CREATE TABLE respuestas(
	preguntaid INT NOT NULL,
	respuesta varchar(255) NOT NULL,
	usuario varchar(255) NOT NULL,
	FOREIGN KEY (usuario) references usuario (usuario)
		ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (preguntaid) references preguntas (id)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);



CREATE TABLE producto(
	id INT NOT NULL AUTO_INCREMENT ,
	nombre varchar(255) NOT NULL,
	descripcion varchar(255) NOT NULL,
	valor INT NOT NULL, 
	dueno VARCHAR(255) NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (dueno) references usuario (usuario)
		ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ordenes(
	id INT NOT NULL AUTO_INCREMENT ,
	dueno VARCHAR(255) NOT NULL,
	FECHA DATETIME NOT NULL, 
	PRIMARY KEY(id),
	FOREIGN KEY (dueno) references usuario(usuario)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);

CREATE TABLE carrito(
	idorden INT NOT NULL,
	idproducto INT NOT NULL,
	FOREIGN KEY (idorden) references ordenes(id)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (idproducto )references producto(id)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);
