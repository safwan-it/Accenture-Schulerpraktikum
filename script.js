// ===== E-Mail-Button =====
// Die Empfängeradresse gibt der Betreuer bei Bedarf. Einfach hier eintragen:
const EMPFAENGER = "";
const BETREFF = "Bewerbung virtuelles Schülerpraktikum";

document.getElementById("mailButton").addEventListener("click", function () {
  window.location.href =
    "mailto:" + EMPFAENGER + "?subject=" + encodeURIComponent(BETREFF);
});

// ===== Checkliste mit Fortschrittsbalken =====
const checkboxen = document.querySelectorAll("#checklist input");
const fortschrittFill = document.getElementById("progressFill");
const fortschrittText = document.getElementById("progressText");
const SPEICHER_KEY = "teamD-checkliste";

function fortschrittAktualisieren() {
  let erledigt = 0;

  checkboxen.forEach(function (box) {
    box.parentElement.classList.toggle("erledigt", box.checked);
    if (box.checked) erledigt++;
  });

  const prozent = (erledigt / checkboxen.length) * 100;
  fortschrittFill.style.width = prozent + "%";
  fortschrittText.textContent = erledigt + " von " + checkboxen.length + " erledigt";

  if (erledigt === checkboxen.length) {
    fortschrittText.textContent = "Alles erledigt! 🎉";
  }

  speichern();
}

// Haken im Browser merken, damit sie nach dem Neuladen noch da sind
function speichern() {
  try {
    const status = Array.from(checkboxen).map(function (box) {
      return box.checked;
    });
    localStorage.setItem(SPEICHER_KEY, JSON.stringify(status));
  } catch (e) {
    // Speichern nicht möglich, Seite funktioniert trotzdem
  }
}

function laden() {
  try {
    const status = JSON.parse(localStorage.getItem(SPEICHER_KEY));
    if (status) {
      checkboxen.forEach(function (box, i) {
        box.checked = status[i] === true;
      });
    }
  } catch (e) {
    // nichts gespeichert
  }
}

checkboxen.forEach(function (box) {
  box.addEventListener("change", fortschrittAktualisieren);
});

document.getElementById("resetChecklist").addEventListener("click", function () {
  checkboxen.forEach(function (box) {
    box.checked = false;
  });
  fortschrittAktualisieren();
});

laden();
fortschrittAktualisieren();

// ===== FAQ aufklappen / zuklappen =====
document.querySelectorAll(".faq__question").forEach(function (frage) {
  frage.addEventListener("click", function () {
    const item = frage.parentElement;
    const antwort = item.querySelector(".faq__answer");
    const istOffen = item.classList.contains("offen");

    // alle anderen schließen
    document.querySelectorAll(".faq__item").forEach(function (anderes) {
      anderes.classList.remove("offen");
      anderes.querySelector(".faq__answer").style.maxHeight = null;
    });

    if (!istOffen) {
      item.classList.add("offen");
      antwort.style.maxHeight = antwort.scrollHeight + "px";
    }
  });
});
