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
CREATE PROCEDURE crear_pregunta( IN email varchar (255), IN pregunta varchar (255))
BEGIN
INSERT INTO preguntas (email,pregunta) VALUES (email, pregunta);
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
SELECT * FROM preguntas;
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
Select count(email) from usuario WHERE usuario.email=email;
END;//


DELIMITER //
CREATE PROCEDURE validate_password( IN email varchar (255), IN password varchar(255))
BEGIN
Select count(username) from usuario WHERE usuario.email=email and usuario.contrasena=password;
END;//

xz

DELIMITER //
CREATE PROCEDURE crear_producto(IN nombre varchar(255), IN descripcion varchar (255), IN valor int(11), IN dueno varchar(255))
BEGIN
    INSERT INTO producto (nombre,descripcion,valor,dueno) VALUES (nombre,descripcion,valor,dueno);
END; //

DELIMITER //
CREATE PROCEDURE actualizar_producto(IN id int(11),IN nombre varchar(255), IN descripcion varchar (255), IN valor int(11), IN dueno varchar(255))
BEGIN
UPDATE producto 
    SET                                                             
    nombre = nombre,
    descripcion = descripcion,
    valor = valor,
    dueno = dueno
    WHERE producto.id = id;
END;
//

DELIMITER //
CREATE PROCEDURE eliminar_producto( IN id int (11))
BEGIN
DELETE FROM producto
    WHERE producto.id = id;
END;//

DELIMITER //
CREATE PROCEDURE obtener_producto_por_id( IN id int (11))
BEGIN
SELECT * FROM producto WHERE producto.id = id;
END;//

DELIMITER //
CREATE PROCEDURE obtener_productos()
BEGIN
SELECT * FROM producto;
END;//

DELIMITER //
CREATE PROCEDURE handle_producto(IN id int(11), IN nombre varchar(255), IN descripcion varchar (255), IN valor int(11), IN dueno varchar(255), IN statement varchar(30))
BEGIN
	IF statement = "Insert" THEN
    	INSERT INTO producto (nombre,descripcion,valor,dueno) VALUES (nombre,descripcion,valor,dueno);
    ELSEIF statement = "Update" THEN
    	UPDATE producto 
        SET 
        nombre = nombre,
        descripcion = descripcion,
        valor = valor,
        dueno = dueno
        WHERE producto.id = id;
    END IF;
END;
//

DELIMITER //
CREATE PROCEDURE crear_sesion( IN email varchar(255), IN token_sesion varchar (255), IN activo varchar (10))
BEGIN
	INSERT INTO sesion (email,token_sesion,activo, fecha) VALUES (email, token_sesion, activo, CURRENT_TIMESTAMP());
END;
//

DELIMITER //
CREATE PROCEDURE borrar_sesion( IN token_sesion varchar (255))
BEGIN
	DELETE FROM sesion WHERE token_sesion=token_sesion;
END;
//

DELIMITER //
CREATE PROCEDURE cambiar_estado_sesion( IN token_sesion varchar (255), IN activo varchar (10))
BEGIN
	UPDATE sesion 
    SET activo = activo
    WHERE token_sesion=token_sesion;
END;
//

DELIMITER //
CREATE PROCEDURE get_sesion( IN token_sesion varchar (255))
BEGIN
	SELECT count(token_sesion) FROM sesion
    where token_sesion=token_sesion;
END;
//

DELIMITER //
CREATE PROCEDURE get_username_from_session( IN token_sesion varchar (255))
BEGIN
	SELECT usuario FROM usuario
    JOIN sesion ON sesion.email = usuario.email
    where sesion.token_sesion = token_sesion;
END;
//