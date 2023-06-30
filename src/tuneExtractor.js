//https://github.com/ShaneMcC/beeps

const songSources = [
    'https://raw.githubusercontent.com/ShaneMcC/beeps/master/pacman.sh'
];

Promise.all(songSources.map(songSource => fetch(songSource).then(response => {
    response.text().then((text) => {
        extractTune(text);
    });
}))).then(() => {
    
});




function extractTune(bashCommand) {
    
    const frequencyRegex = /(-f \d{1,3})/g;
    const durationRegex = /(-l \d{1,3})/g;
    
    const frequencies = bashCommand.match(frequencyRegex);
    const durations = bashCommand.match(durationRegex);
    console.log('---');
    console.log(frequencies.length);
    console.log(durations.length);
    console.log('---');
    
    return frequencies.map((frequency, index) => {
        const duration = durations[index].replace('-l ', '');
        frequency = frequency.replace('-f ', '');
    
        console.log(`Note(${frequency}, ${duration}),`);
    });
}

