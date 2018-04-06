var voto = "";

function votoNulo(){
	voto = "nulo";
	var xmlhttp = new XMLHttpRequest();
	xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                //document.write("A mi me funciona papu");
            }
        };
    xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=" + voto, true);
    xmlhttp.send();
    window.location="../App.Vista/HomeView.html";
}

function votoPri(){
	voto = "pri";
	var xmlhttp = new XMLHttpRequest();
	xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                //document.write("Voto para el pri");
            }
        };
    xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=" + voto, true);
    xmlhttp.send();
    window.location="../App.Vista/HomeView.html";
}

function votoPan(){
    voto = "pan";
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                //document.write("Voto para el pan");
            }
        };
    xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=" + voto, true);
    xmlhttp.send();
    window.location="../App.Vista/HomeView.html";
}

function votoMorena(){
    voto = "morena";
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                //document.write("Voto para el morena");
            }
        };
    xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=" + voto, true);
    xmlhttp.send();
    window.location="../App.Vista/HomeView.html";
}

function votoPrd(){
    voto = "prd";
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                //document.write("Voto para el Prd");
            }
        };
    xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=" + voto, true);
    xmlhttp.send();
    window.location="../App.Vista/HomeView.html";
}