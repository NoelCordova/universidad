<?php
	
	$host = "localhost";
	$user = "root";
	$pass = "";
	$database = "votos";

	$q = $_GET['q'];

	$connection = mysql_connect($host, $user, $pass) or die('Error en la conexion: ' . mysql_error());

	mysql_select_db($database) or die('Error en conexion db: ' . mysql_error());

	if($q == "nulo"){
		votoNulo();
	}elseif($q == "pri"){
		votoPri();
	}elseif($q == "pan"){
		votoPan();
	}elseif($q == "morena"){
		votoMorena();
	}elseif($q == "prd"){
		votoPrd();
	}elseif($q == 0){
		/*var votoPRI = getvotoPri();
		var votoPAN = getvotoPan();
		var votoMORENA = getvotoMorena();
		var votoPRD = getvotoPrd();
		var votoNULO = getvotoNulo();*/

		$votos = array(getvotoPri(), getvotoPan(), getvotoMorena(), getvotoPrd(), getvotoNulo());
		$myJSON = json_encode($votos);
		echo $myJSON;
	}

	function votoPri(){
		$query = "SELECT votos FROM stats WHERE id=1";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPri = $row['votos'];
		$votosPri = $votosPri + 1;
		$query = "UPDATE stats SET votos='$votosPri' WHERE id=1";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
	}

	function votoPan(){
		$query = "SELECT votos FROM stats WHERE id=2";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPan = $row['votos'];
		$votosPan = $votosPan + 1;
		$query = "UPDATE stats SET votos='$votosPan' WHERE id=2";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
	}

	function votoMorena(){
		$query = "SELECT votos FROM stats WHERE id=3";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosMorena = $row['votos'];
		$votosMorena = $votosMorena + 1;
		$query = "UPDATE stats SET votos='$votosMorena' WHERE id=3";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
	}

	function votoPrd(){
		$query = "SELECT votos FROM stats WHERE id=4";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPrd = $row['votos'];
		$votosPrd = $votosPrd + 1;
		$query = "UPDATE stats SET votos='$votosPrd' WHERE id=4";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
	}

	function votoNulo(){
		$query = "SELECT votos FROM stats WHERE id=5";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosNulos = $row['votos'];
		$votosNulos = $votosNulos + 1;
		$query = "UPDATE stats SET votos='$votosNulos' WHERE id=5";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		return $votosNulos;
	}

	function getvotoPri(){
		$query = "SELECT votos FROM stats WHERE id=1";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPri = $row['votos'];
		return $votosPri;
	}

	function getvotoPan(){
		$query = "SELECT votos FROM stats WHERE id=2";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPan = $row['votos'];
		return $votosPan;
	}

	function getvotoMorena(){
		$query = "SELECT votos FROM stats WHERE id=3";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosMorena = $row['votos'];
		return $votosMorena;
	}

	function getvotoPrd(){
		$query = "SELECT votos FROM stats WHERE id=4";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosPrd = $row['votos'];
		return $votosPrd;
	}

	function getvotoNulo(){
		$query = "SELECT votos FROM stats WHERE id=5";
		$result = mysql_query($query) or die('Error en la consulta: ' . mysql_error());
		$row = mysql_fetch_array($result);
		$votosNulo = $row['votos'];
		return $votosNulo;
	}

	mysql_close($connection);

?>