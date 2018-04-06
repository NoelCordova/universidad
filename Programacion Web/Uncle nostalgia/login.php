<?php
	session_start(); 
	include 'connection.php';
	$table = "usuarios";

	if(isset($_POST['login'])){
		$emailUsr = $_POST['email'];
		$passwordUsr = $_POST['pass'];

		$log = mysql_query("SELECT * FROM $table WHERE email='$emailUsr' AND password='$passwordUsr'") or die(mysql_error());

		if (mysql_num_rows($log)>0) {

			$row = mysql_fetch_array($log);

			$_SESSION["email"] = $row['email'];

			$nickUsr = $row['nickname'];
			$_SESSION["nickname"] = $nickUsr;

			$nombreUsr = $row['nombre'];
			$_SESSION["nombre"] = $nombreUsr;

			$nombreUsr = $row['apellido'];
			$_SESSION["apellido"] = $nombreUsr;

			$_SESSION["pass"] = $row['password'];			

			echo '<script> window.location="homeUsuario.php"; </script>';
		}
		else{
			echo '<script> alert("Usuario o contraseña incorrectos.");</script>';
			echo '<script> window.location="index.php"; </script>';
		}
	}
?>	