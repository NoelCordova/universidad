<?php 

	$servername = "localhost";
	$username = "root";
	$password = "";
	$database = "uncle";

	$connection = mysql_connect($servername, $username, $password) or die("Error al conectar con el servidor");
	mysql_select_db($database, $connection)or die("Error al conectar con la Base de Datos");
?>