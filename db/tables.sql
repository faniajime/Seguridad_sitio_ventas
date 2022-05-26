

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
	email varchar(255),
	pregunta varchar(255) NOT NULL,
	PRIMARY KEY (id)
);

CREATE TABLE respuestas(
	preguntaid INT NOT NULL,
	respuesta varchar(255) NOT NULL,
	email varchar(255) NOT NULL,
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
	valor varchar(255) NOT NULL, 
	dueno VARCHAR(255) NOT NULL
	PRIMARY KEY (id),
	FOREIGN KEY (dueno) references usuario (usuario)
		ON DELETE CASCADE ON UPDATE CASCADE
);


CREATE TABLE carrito(
	usuario VARCHAR(255) NOT NULL,
	idproducto INT NOT NULL,
	FOREIGN KEY (usuario) references usuario(usuario)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	FOREIGN KEY (idproducto )references producto(id)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);


CREATE TABLE sesion(
	email VARCHAR(255) NOT NULL,
	token_sesion VARCHAR(255) NOT NULL,
	activo VARCHAR(5) NOT NULL,
	fecha DATETIME NOT NULL, 
);
