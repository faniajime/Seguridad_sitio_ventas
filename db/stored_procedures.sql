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
SELECT * FROM usuario WHERE usuario.usuario = usuario;
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
Select count(usuario) from usuario WHERE usuario.email=email and usuario.contrasena=password;
END;//


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


DELIMITER //
CREATE PROCEDURE add_to_cart( IN user varchar (255), IN idproduct INT)
BEGIN
	INSERT INTO carrito (usuario,idproducto) VALUES (user, idproduct);
END;
//

DELIMITER //
CREATE PROCEDURE remove_from_cart( IN user varchar (255), IN idproduct INT)
BEGIN
	DELETE FROM carrito WHERE usuario = user AND idproducto=idproduct;
END;
//

DELIMITER //
CREATE PROCEDURE delete_cart( IN user varchar (255))
BEGIN
	DELETE FROM carrito WHERE usuario = user;
END;
//

DELIMITER //
CREATE PROCEDURE get_total( IN user varchar (255))
BEGIN
	SELECT SUM(valor) FROM producto 
    RIGHT JOIN carrito on carrito.idproducto = producto.id
    WHERE carrito.usuario = user;
END;
//

DELIMITER //
CREATE PROCEDURE buy_cart( IN user varchar (255), IN ammount INT)
BEGIN
    INSERT INTO compras (usuario, total, fecha) VALUES (user, ammount, CURRENT_TIMESTAMP());
	DELETE FROM producto WHERE id IN (SELECT idproducto FROM carrito where usuario=user);
    DELETE FROM carrito WHERE usuario=user;
END
//

DELIMITER //
CREATE PROCEDURE get_cart( IN user varchar (255))
BEGIN
	SELECT * FROM producto 
    RIGHT JOIN carrito on producto.id = carrito.idproducto
    WHERE carrito.usuario = user;
END;
//


DELIMITER //
CREATE PROCEDURE get_products_by_keyword( IN keyword varchar (255))
BEGIN
	SELECT * FROM producto 
    WHERE producto.nombre LIKE CONCAT('%',keyword,'%')
    UNION
    SELECT * FROM producto 
    WHERE producto.dueno LIKE CONCAT('%',keyword,'%')
    UNION
    SELECT * FROM producto 
    WHERE producto.valor LIKE CONCAT('%',keyword,'%')
    UNION
    SELECT * FROM producto 
    WHERE producto.descripcion LIKE CONCAT('%',keyword,'%');
END
//

DELIMITER //
CREATE PROCEDURE is_in_cart( IN productID INT)
BEGIN
	SELECT count(productoid) FROM carrito
    WHERE productoid = productID;
END
//

DELIMITER //
CREATE PROCEDURE hasProductsInCart( IN usuario varchar(255))
BEGIN
	SELECT count(usuario) FROM carrito
    WHERE usuario = usuario;
END
//

