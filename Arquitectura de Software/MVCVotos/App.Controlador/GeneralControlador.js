var xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        document.getElementById("votosPri").innerHTML = myObj[0];
        document.getElementById("votosPan").innerHTML = myObj[1];
        document.getElementById("votosMorena").innerHTML = myObj[2];
        document.getElementById("votosPrd").innerHTML = myObj[3];
        document.getElementById("votosNulos").innerHTML = myObj[4];
    }
};
xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=0", true);
xmlhttp.send();