// "Mehr anzeigen"-Buttons auf den Cards
const buttons = document.querySelectorAll(".mehr-button");

buttons.forEach(function (button) {
    button.addEventListener("click", function () {
        const text = button.nextElementSibling;
        const sichtbar = text.classList.toggle("sichtbar");

        button.setAttribute("aria-expanded", sichtbar);
        button.textContent = sichtbar ? "Weniger anzeigen" : "Mehr anzeigen";
    });
});

// "Antwort anzeigen"-Buttons im Quiz – zeigt das Antwort-Foto
const antwortButtons = document.querySelectorAll(".antwort-button");

antwortButtons.forEach(function (button) {
    button.addEventListener("click", function () {
        const bild = button.nextElementSibling;
        const sichtbar = bild.classList.toggle("sichtbar");

        button.setAttribute("aria-expanded", sichtbar);
        button.textContent = sichtbar ? "Antwort verstecken" : "Antwort anzeigen";
    });
});
