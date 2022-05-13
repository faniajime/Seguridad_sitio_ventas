DELIMITER //
CREATE PROCEDURE crear_usuario(IN nombre varchar(255), IN usuario varchar (255), IN email VARCHAR(255), IN telefono int(8), IN contrasena varchar(255), IN direccion varchar(255))
BEGIN
    INSERT INTO usuario (nombre,usuario,email,telefono,contrasena,direccion) VALUES (nombre,usuario,email,telefono,contrasena,direccion);
END; //


DELIMITER //
CREATE PROCEDURE actualizar_usuario(IN nombre varchar(255), IN usuario varchar (255), IN email VARCHAR(255), IN telefono int(8), IN contrasena varchar(255), IN direccion varchar(255))
BEGIN
UPDATE usuario 
    SET 
    nombre = nombre,
    email = email, 
    telefono = telefono,
    contrasena = contrasena,
    direccion = direccion
    WHERE usuario.usuario = usuario;
END;
//

DELIMITER //
CREATE PROCEDURE eliminar_usuario( IN usuario varchar (255))
BEGIN
DELETE FROM usuario
    WHERE usuario=usuario;
END;//


DELIMITER //
CREATE PROCEDURE obtener_usuario( IN usuario varchar (255))
BEGIN
SELECT * FROM usuario WHERE usuario = usuario;
END;//


DELIMITER //
CREATE PROCEDURE crear_pregunta( IN usuario varchar (255), IN pregunta varchar (255))
BEGIN
INSERT INTO preguntas (usuario,pregunta) VALUES (usuario, pregunta);
END;//

DELIMITER //
CREATE PROCEDURE editar_pregunta( IN id int, IN pregunta varchar (255))
BEGIN
UPDATE preguntas
    SET 
    pregunta = pregunta 
    WHERE pregunta.id = id;
END;//


DELIMITER //
CREATE PROCEDURE eliminar_pregunta( IN id int)
BEGIN
DELETE FROM preguntas
    WHERE preguntas.id = id;
END;//


DELIMITER //
CREATE PROCEDURE get_preguntas( )
BEGIN
SELECT * FROM PREGUNTAS;
END;//


DELIMITER //
CREATE PROCEDURE get_user_by_username( IN username varchar (255))
BEGIN
SELECT * FROM usuario WHERE username = username;
END;//

DELIMITER //
CREATE PROCEDURE username_exists( IN username varchar (255))
BEGIN
Select count(usuario) from usuario WHERE usuario=username;
END;//



DELIMITER //
CREATE PROCEDURE email_exists( IN email varchar (255))
BEGIN
Select count(email) from usuario WHERE email=email;
END;//


DELIMITER //
CREATE PROCEDURE validate_password( IN username varchar (255), IN password varchar(255))
BEGIN
Select count(username) from usuario WHERE usuario.username=username and usuario.password=password;
END;//