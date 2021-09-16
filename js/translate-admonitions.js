
// Tradução dos admonitions
let en_pt = {
    "Note": "Aviso",
    "Tip": "Dica",
    "Question": "Pergunta",
    "Warning": "Cuidado",
    "Example": "Tarefa"
};

let admonitions_to_translate = document.querySelectorAll(".admonition-title");
for (var i = 0; i < admonitions_to_translate.length; i++) {
    let el = admonitions_to_translate[i];
    
    if (el.innerText in en_pt) {
        el.innerText = en_pt[el.innerText];
    }
}


/* Contagem automática de tarefas e perguntas */
let counters = ["example", "question"];
counters.forEach(function (admo_type) {
    let elements = document.querySelectorAll(".admonition." + admo_type + " > .admonition-title");
    for (let i = 0; i < elements.length; i++) {
        let el = elements[i];
        el.innerText += " " + (i+1);
    }    
});
