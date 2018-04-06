<?php 
	//echo "Work on it :D";
	include 'connection.php';
	$table = "usuarios";

	$nombreUsr = $_POST['nombre'];
	$apellidoUsr = $_POST['apellido'];
	$nickUsr = $_POST['nick'];
	$emailUsr = $_POST['email'];

	//$sql = 'INSERT INTO `' . $database . '`.`'.$table.'` (`nombre` , `apellido` , `nickname` , `email`, `password`) VALUES ("' . $nombreUsr . '", "' . $apellidoUsr . '", "' . $nickUsr . '", "' . $emailUsr . '", "' . $passwordUsr . '")';

	$sql = "UPDATE '$table' SET nombre='$nombreUsr' WHERE email='$emailUsr'";//, apellido='$apellidoUsr', nickname='$nickUsr' WHERE email='$emailUsr'";

	mysql_select_db($database, $connection);
	$retry_value = mysql_query($sql, $connection);

	if(!$retry_value){
		die("Error " . mysql_error());
	}

	//echo '<script>alert("Registro completo!");</script>';
	echo '<script> window.location="homeUsuario.php"; </script>';
	mysql_close($connection);
?>