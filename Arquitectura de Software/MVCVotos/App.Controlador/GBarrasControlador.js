var xmlhttp = new XMLHttpRequest();
xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var myObj = JSON.parse(this.responseText);
        new Morris.Bar({
            element: 'GraphBarras',
            data: [
                { Partidos: 'PRI', Votos: myObj[0] },
                { Partidos: 'PAN', Votos: myObj[1] },
                { Partidos: 'MORENA', Votos: myObj[2] },
                { Partidos: 'PRD', Votos: myObj[3] },
                { Partidos: 'NULO', Votos: myObj[4] }
            ],
            xkey: 'Partidos',
            ykeys: ['Votos'],
            labels: ['Votos totales'],
            resize: true
        });
    }
};
xmlhttp.open("GET", "../App.Modelo/VotosModelo.php?q=0", true);
xmlhttp.send(); 