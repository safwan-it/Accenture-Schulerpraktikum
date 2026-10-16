/* =========================================================
   Accenture Student Internship Portal – JavaScript

   So ist jede Funktion aufgebaut (immer das gleiche Muster):
     1. Element suchen      → document.querySelector("...")
     2. Auf Klick warten    → element.addEventListener("click", function () { ... })
     3. Etwas verändern     → Klasse an/aus, Text ändern, Element zeigen/verstecken

   Jede Funktion prüft am Anfang, ob ihr Element auf der aktuellen
   Seite existiert. Wenn nicht, hört sie sofort auf (return).
   So gibt es keine Fehler in der Konsole.
   ========================================================= */


/* ---------- Hilfsfunktionen: im Browser speichern und laden ---------- */
// localStorage merkt sich Werte, auch wenn man die Seite schließt.
// "try/catch" bedeutet: Versuche es – und falls der Browser das Speichern verbietet,
// passiert einfach nichts (statt einer Fehlermeldung).

function speichern(name, wert) {
  try {
    localStorage.setItem(name, wert);
  } catch (fehler) {
    // Speichern nicht erlaubt → nichts tun
  }
}

function laden(name) {
  try {
    return localStorage.getItem(name);
  } catch (fehler) {
    return null; // nichts gespeichert
  }
}


/* ---------- 1. Dark Mode (gemeinsam, alle Seiten) ---------- */
function darkModeEinrichten() {
  const knopf = document.querySelector("#dark-btn");
  const seite = document.documentElement; // das <html>-Element
  if (!knopf) {
    return;
  }

  // Beim Laden: Wurde früher der dunkle Modus gewählt?
  if (laden("theme") === "dark") {
    seite.classList.add("dark");
  }
  symbolAnpassen();

  // Beim Klick: Modus wechseln und merken
  knopf.addEventListener("click", function () {
    if (seite.classList.contains("dark")) {
      seite.classList.remove("dark");
      speichern("theme", "light");
    } else {
      seite.classList.add("dark");
      speichern("theme", "dark");
    }
    symbolAnpassen();
  });

  // Mond im hellen Modus, Sonne im dunklen Modus
  function symbolAnpassen() {
    if (seite.classList.contains("dark")) {
      knopf.textContent = "☀️";
      knopf.setAttribute("aria-label", "Hellen Modus aktivieren");
    } else {
      knopf.textContent = "🌙";
      knopf.setAttribute("aria-label", "Dunklen Modus aktivieren");
    }
  }
}


/* ---------- 2. Menü-Button auf dem Handy (gemeinsam) ---------- */
function menueEinrichten() {
  const knopf = document.querySelector("#menu-btn");
  const links = document.querySelector(".nav-links");
  if (!knopf || !links) {
    return;
  }

  knopf.addEventListener("click", function () {
    // Die Klasse "offen" sorgt im CSS dafür, dass das Menü sichtbar wird
    if (links.classList.contains("offen")) {
      links.classList.remove("offen");
      knopf.setAttribute("aria-expanded", "false");
    } else {
      links.classList.add("offen");
      knopf.setAttribute("aria-expanded", "true");
    }
  });
}


/* ---------- 3. "Nach oben"-Button (gemeinsam) ---------- */
function nachObenEinrichten() {
  const knopf = document.querySelector("#nach-oben");
  if (!knopf) {
    return;
  }

  // Beim Scrollen: Button erst zeigen, wenn man mehr als 400 Pixel nach unten gescrollt hat
  window.addEventListener("scroll", function () {
    if (window.scrollY > 400) {
      knopf.classList.add("sichtbar");
    } else {
      knopf.classList.remove("sichtbar");
    }
  });

  // Beim Klick: sanft ganz nach oben scrollen
  knopf.addEventListener("click", function () {
    window.scrollTo({ top: 0, behavior: "smooth" });
  });
}


/* ---------- 4. "Mehr anzeigen"-Buttons (Team B) ---------- */
function mehrAnzeigenEinrichten() {
  const knoepfe = document.querySelectorAll(".mehr-btn");

  for (const knopf of knoepfe) {
    knopf.addEventListener("click", function () {
      // den versteckten Text in derselben Karte suchen
      const karte = knopf.parentElement;
      const text = karte.querySelector(".mehr-text");

      if (text.classList.contains("offen")) {
        text.classList.remove("offen");
        knopf.textContent = "Mehr anzeigen ▼";
        knopf.setAttribute("aria-expanded", "false");
      } else {
        text.classList.add("offen");
        knopf.textContent = "Weniger anzeigen ▲";
        knopf.setAttribute("aria-expanded", "true");
      }
    });
  }
}


/* ---------- 5. Roadmap (Team A – Startseite) ---------- */
// Die Texte der Tage stehen im HTML (Attribut data-info an jedem Tag-Button).
// JavaScript macht nur zwei Dinge:
//   a) Woche 1 / Woche 2 umschalten
//   b) beim Klick auf einen Tag dessen Text unten anzeigen
function roadmapEinrichten() {
  const woche1Knopf = document.querySelector("#woche-1-btn");
  const woche2Knopf = document.querySelector("#woche-2-btn");
  const woche1Liste = document.querySelector("#woche-1");
  const woche2Liste = document.querySelector("#woche-2");
  const tagKnoepfe = document.querySelectorAll(".tag-btn");
  const titel = document.querySelector("#tag-titel");
  const text = document.querySelector("#tag-text");
  if (!woche1Knopf) {
    return; // nicht auf der Startseite
  }

  // a) Klick auf "Woche 1"
  woche1Knopf.addEventListener("click", function () {
    woche1Liste.hidden = false;   // Woche 1 zeigen
    woche2Liste.hidden = true;    // Woche 2 verstecken
    woche1Knopf.classList.add("aktiv");
    woche2Knopf.classList.remove("aktiv");
    hinweisZeigen();
  });

  // a) Klick auf "Woche 2"
  woche2Knopf.addEventListener("click", function () {
    woche1Liste.hidden = true;
    woche2Liste.hidden = false;
    woche1Knopf.classList.remove("aktiv");
    woche2Knopf.classList.add("aktiv");
    hinweisZeigen();
  });

  // b) Klick auf einen Tag
  for (const knopf of tagKnoepfe) {
    knopf.addEventListener("click", function () {
      // zuerst bei allen Tagen die Markierung entfernen ...
      for (const andererKnopf of tagKnoepfe) {
        andererKnopf.classList.remove("aktiv");
      }
      // ... dann nur den angeklickten Tag markieren
      knopf.classList.add("aktiv");

      // Text aus dem HTML holen und unten anzeigen
      const tag = knopf.querySelector("strong").textContent;   // z. B. "Tag 3"
      const thema = knopf.querySelector("span").textContent;   // z. B. "Teamarbeit"
      titel.textContent = tag + ": " + thema;
      titel.hidden = false;
      text.textContent = knopf.dataset.info;                  // liest data-info="..."
    });
  }

  // Startzustand des Textfeldes: nur der Hinweis, keine Überschrift
  function hinweisZeigen() {
    titel.hidden = true;
    text.textContent = "Klicke auf einen Tag, um mehr darüber zu erfahren.";
  }
}


/* ---------- 6. Video-Ersatz (Team A – Startseite) ---------- */
// YouTube spielt eingebettete Videos nur auf echten Webseiten ab (Adresse beginnt mit http/https).
// Öffnet man index.html per Doppelklick, beginnt die Adresse mit "file:" und YouTube zeigt "Fehler 153".
// Nur in diesem Fall: Player entfernen und stattdessen das Vorschaubild zeigen (steht schon im HTML).
function videoErsatzEinrichten() {
  const player = document.querySelector(".video-box iframe");
  const vorschau = document.querySelector("#video-vorschau");
  if (!player || !vorschau) {
    return;
  }

  if (window.location.protocol === "file:") {
    player.remove();
    vorschau.hidden = false;
  }
}


/* ---------- 7. Suchfeld (Glossar auf der Startseite) ---------- */
// Man gibt der Funktion drei Dinge mit:
//   suchfeldId   → das Eingabefeld
//   eintraege    → alle Einträge, die durchsucht werden
//   hinweisId    → der Text "Nichts gefunden"
function sucheEinrichten(suchfeldId, eintraegeSelektor, hinweisId) {
  const suchfeld = document.querySelector(suchfeldId);
  const eintraege = document.querySelectorAll(eintraegeSelektor);
  const hinweis = document.querySelector(hinweisId);
  if (!suchfeld) {
    return;
  }

  // "input" passiert bei jedem Buchstaben, den man tippt
  suchfeld.addEventListener("input", function () {
    const suchbegriff = suchfeld.value.toLowerCase().trim(); // klein geschrieben, ohne Leerzeichen am Rand
    let treffer = 0;

    for (const eintrag of eintraege) {
      const eintragText = eintrag.textContent.toLowerCase();
      if (eintragText.includes(suchbegriff)) {
        eintrag.style.display = "";      // passt → normal anzeigen
        treffer = treffer + 1;
      } else {
        eintrag.style.display = "none";  // passt nicht → verstecken
      }
    }

    // Hinweis nur zeigen, wenn gar nichts gefunden wurde
    if (treffer === 0) {
      hinweis.style.display = "block";
    } else {
      hinweis.style.display = "none";
    }
  });
}


/* ---------- 8. Checkliste mit Fortschrittsbalken (Team D) ---------- */
function checklisteEinrichten() {
  const kaestchen = document.querySelectorAll(".checkliste input");
  const balken = document.querySelector("#fortschritt-balken");
  const anzeige = document.querySelector("#fortschritt-text");
  if (kaestchen.length === 0) {
    return;
  }

  // Beim Laden: gespeicherte Häkchen wiederherstellen
  for (let i = 0; i < kaestchen.length; i++) {
    if (laden("checkliste-" + i) === "ja") {
      kaestchen[i].checked = true;
    }
  }
  fortschrittAnzeigen();

  // Bei jeder Änderung: speichern und Fortschritt neu berechnen
  for (let i = 0; i < kaestchen.length; i++) {
    kaestchen[i].addEventListener("change", function () {
      if (kaestchen[i].checked) {
        speichern("checkliste-" + i, "ja");
      } else {
        speichern("checkliste-" + i, "nein");
      }
      fortschrittAnzeigen();
    });
  }

  function fortschrittAnzeigen() {
    let erledigt = 0;

    for (const box of kaestchen) {
      const zeile = box.parentElement.parentElement; // input → label → li
      if (box.checked) {
        erledigt = erledigt + 1;
        zeile.classList.add("erledigt");      // durchgestrichen
      } else {
        zeile.classList.remove("erledigt");
      }
    }

    const prozent = Math.round((erledigt / kaestchen.length) * 100);
    balken.style.width = prozent + "%";

    anzeige.textContent = erledigt + " von " + kaestchen.length + " erledigt";
    if (prozent === 100) {
      anzeige.textContent = anzeige.textContent + " – du bist bereit!";
    }
  }
}


/* ---------- 9. FAQ zum Auf- und Zuklappen (Team D) ---------- */
function faqEinrichten() {
  const fragen = document.querySelectorAll(".faq-frage");

  for (const frage of fragen) {
    frage.addEventListener("click", function () {
      const eintrag = frage.parentElement; // das .faq-item um Frage und Antwort
      // Die Klasse "offen" zeigt im CSS die Antwort an
      if (eintrag.classList.contains("offen")) {
        eintrag.classList.remove("offen");
        frage.setAttribute("aria-expanded", "false");
      } else {
        eintrag.classList.add("offen");
        frage.setAttribute("aria-expanded", "true");
      }
    });
  }
}


/* ---------- 10. Aktuelles Jahr im Footer (gemeinsam) ---------- */
function jahrEinsetzen() {
  const jahr = document.querySelector("#jahr");
  if (jahr) {
    jahr.textContent = new Date().getFullYear();
  }
}


/* ---------- 11. Antwort-Buttons (Rätsel auf der Coding-Seite) ---------- */
function antwortAnzeigenEinrichten() {
  const knoepfe = document.querySelectorAll(".antwort-btn");

  for (const knopf of knoepfe) {
    knopf.addEventListener("click", function () {
      // das Antwortbild liegt in derselben Karte wie der Button
      const karte = knopf.parentElement;
      const bild = karte.querySelector(".antwort-bild");

      if (bild.classList.contains("offen")) {
        bild.classList.remove("offen");
        knopf.textContent = "Antwort anzeigen";
        knopf.setAttribute("aria-expanded", "false");
      } else {
        bild.classList.add("offen");
        knopf.textContent = "Antwort verstecken";
        knopf.setAttribute("aria-expanded", "true");
      }
    });
  }
}


/* ---------- Start: alle Funktionen ausführen ---------- */
darkModeEinrichten();
menueEinrichten();
nachObenEinrichten();
mehrAnzeigenEinrichten();
roadmapEinrichten();
videoErsatzEinrichten();
sucheEinrichten("#glossar-suche", "#glossar-bereich .suchbar", "#glossar-keine-treffer");
checklisteEinrichten();
faqEinrichten();
antwortAnzeigenEinrichten();
jahrEinsetzen();