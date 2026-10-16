// Team D – JavaScript

// Zeigt dem CSS, dass JavaScript läuft (für die Einblend-Animationen)
document.documentElement.classList.add("js");

// Hat jemand im System "Bewegung reduzieren" eingestellt?
const wenigBewegung = window.matchMedia("(prefers-reduced-motion: reduce)").matches;


// 1. Wechselnde Wörter in der großen Überschrift
const wechselwort = document.getElementById("wechselwort");
const woerter = ["Code.", "Teamwork.", "Git.", "Neues.", "eure Zukunft."];
let wortIndex = 0;

if (!wenigBewegung) {
    setInterval(function () {
        wechselwort.classList.add("raus");
        setTimeout(function () {
            wortIndex = (wortIndex + 1) % woerter.length;
            wechselwort.textContent = woerter[wortIndex];
            wechselwort.classList.remove("raus");
        }, 350);
    }, 2400);
}


// 2. Scroll-Balken oben und aktiver Link in der Navigation
const scrollBalken = document.getElementById("scroll-balken");

function scrollFortschritt() {
    const hoehe = document.documentElement.scrollHeight - window.innerHeight;
    const anteil = hoehe > 0 ? window.scrollY / hoehe : 0;
    scrollBalken.style.transform = "scaleX(" + anteil + ")";
}

window.addEventListener("scroll", scrollFortschritt, { passive: true });
scrollFortschritt();

const navLinks = document.querySelectorAll(".nav-links a");
const bereiche = document.querySelectorAll("main section[id]");

const navBeobachter = new IntersectionObserver(function (eintraege) {
    eintraege.forEach(function (eintrag) {
        if (eintrag.isIntersecting) {
            navLinks.forEach(function (link) {
                link.classList.toggle("aktiv", link.getAttribute("href") === "#" + eintrag.target.id);
            });
        }
    });
}, { rootMargin: "-45% 0px -50% 0px" });

bereiche.forEach(function (bereich) {
    navBeobachter.observe(bereich);
});


// 3. Elemente einblenden, sobald sie ins Bild scrollen
const zeigenElemente = document.querySelectorAll(".zeigen");

zeigenElemente.forEach(function (element) {
    // Nebeneinanderliegende Elemente erscheinen kurz nacheinander
    const geschwister = Array.from(element.parentElement.querySelectorAll(":scope > .zeigen"));
    element.style.setProperty("--verzoegerung", geschwister.indexOf(element) * 100 + "ms");
});

const einblenden = new IntersectionObserver(function (eintraege, beobachter) {
    eintraege.forEach(function (eintrag) {
        if (eintrag.isIntersecting) {
            eintrag.target.classList.add("sichtbar");
            beobachter.unobserve(eintrag.target);
        }
    });
}, { threshold: 0.1 });

zeigenElemente.forEach(function (element) {
    einblenden.observe(element);
});


// 4. Leuchten auf den Karten folgt der Maus
document.querySelectorAll(".karte").forEach(function (karte) {
    karte.addEventListener("pointermove", function (ereignis) {
        const box = karte.getBoundingClientRect();
        karte.style.setProperty("--x", ereignis.clientX - box.left + "px");
        karte.style.setProperty("--y", ereignis.clientY - box.top + "px");
    });
});


// 5. Checkliste mit Fortschrittsring
const aufgaben = document.querySelectorAll(".aufgabe");
const fortschritt = document.getElementById("fortschritt");
const prozentAnzeige = document.getElementById("prozent");
const ring = document.getElementById("ring-fortschritt");
const ringBox = document.getElementById("ring-box");
const zuruecksetzen = document.getElementById("zuruecksetzen");
const UMFANG = 2 * Math.PI * 52; // Umfang des Kreises mit Radius 52
const SPEICHER_NAME = "teamd-checkliste";
let warFertig = false;

ring.style.strokeDasharray = UMFANG;

// Zählt die Häkchen, aktualisiert Text und Ring und sagt, ob alles erledigt ist
function zaehlen() {
    let erledigt = 0;
    aufgaben.forEach(function (box) {
        if (box.checked) {
            erledigt++;
        }
    });

    const anteil = erledigt / aufgaben.length;
    const fertig = erledigt === aufgaben.length;

    prozentAnzeige.textContent = Math.round(anteil * 100) + "%";
    ring.style.strokeDashoffset = UMFANG * (1 - anteil);
    ringBox.classList.toggle("fertig", fertig);

    if (fertig) {
        fortschritt.textContent = "Ihr seid startklar! 🎉";
    } else {
        fortschritt.textContent = erledigt + " von " + aufgaben.length + " erledigt";
    }
    return fertig;
}

// Speichert die Häkchen im Browser, damit sie nach dem Neuladen noch da sind
function speichern() {
    const status = [];
    aufgaben.forEach(function (box) {
        status.push(box.checked);
    });
    try {
        localStorage.setItem(SPEICHER_NAME, JSON.stringify(status));
    } catch (fehler) {
        // Speichern nicht erlaubt (z. B. privates Fenster) – dann eben ohne
    }
}

function laden() {
    try {
        const status = JSON.parse(localStorage.getItem(SPEICHER_NAME)) || [];
        aufgaben.forEach(function (box, i) {
            box.checked = status[i] === true;
        });
    } catch (fehler) {
        // Nichts gespeichert oder Speicher gesperrt – alles bleibt leer
    }
}

aufgaben.forEach(function (box) {
    box.addEventListener("change", function () {
        const fertig = zaehlen();
        speichern();
        // Konfetti nur in dem Moment, in dem das letzte Häkchen gesetzt wird
        if (fertig && !warFertig) {
            konfetti();
        }
        warFertig = fertig;
    });
});

zuruecksetzen.addEventListener("click", function () {
    aufgaben.forEach(function (box) {
        box.checked = false;
    });
    warFertig = zaehlen();
    speichern();
});

laden();
warFertig = zaehlen();


// 6. FAQ: Klick auf eine Frage klappt die Antwort auf oder zu
const knoepfe = document.querySelectorAll(".frage-knopf");

knoepfe.forEach(function (knopf) {
    knopf.addEventListener("click", function () {
        const istOffen = knopf.getAttribute("aria-expanded") === "true";
        knopf.setAttribute("aria-expanded", String(!istOffen));
    });
});


// 7. Konfetti-Regen
const leinwand = document.getElementById("konfetti");
const stift = leinwand.getContext("2d");
const FARBEN = ["#a100ff", "#c56bff", "#ff3fb4", "#ff8a3d", "#4b2bff"];

function konfetti() {
    if (wenigBewegung) {
        return;
    }

    leinwand.width = window.innerWidth;
    leinwand.height = window.innerHeight;

    const teile = [];
    for (let i = 0; i < 160; i++) {
        teile.push({
            x: leinwand.width / 2,
            y: leinwand.height * 0.6,
            vx: (Math.random() - 0.5) * 18,
            vy: Math.random() * -18 - 6,
            groesse: Math.random() * 8 + 5,
            drehung: Math.random() * Math.PI,
            farbe: FARBEN[Math.floor(Math.random() * FARBEN.length)]
        });
    }

    let bilder = 0;

    function zeichnen() {
        stift.clearRect(0, 0, leinwand.width, leinwand.height);

        teile.forEach(function (teil) {
            teil.vy += 0.45; // Schwerkraft
            teil.vx *= 0.99; // Luftwiderstand
            teil.x += teil.vx;
            teil.y += teil.vy;
            teil.drehung += 0.12;

            stift.save();
            stift.translate(teil.x, teil.y);
            stift.rotate(teil.drehung);
            stift.fillStyle = teil.farbe;
            stift.fillRect(-teil.groesse / 2, -teil.groesse / 4, teil.groesse, teil.groesse / 2);
            stift.restore();
        });

        bilder++;
        if (bilder < 200) {
            requestAnimationFrame(zeichnen);
        } else {
            stift.clearRect(0, 0, leinwand.width, leinwand.height);
        }
    }

    zeichnen();
}
