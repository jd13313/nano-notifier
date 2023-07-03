//https://github.com/ShaneMcC/beeps

const songSources = [process.argv[2]];

Promise.all(songSources.map(songSource => fetch(songSource).then(response => {
    response.text().then((text) => {
        extractTune(text);
    });
})))




function extractTune(bashCommand) {
    
    const frequencyRegex = /(-f \d{1,3})/g;
    const durationRegex = /(-l \d{1,3})/g;
    const delayRegex = /(-D \d{1,3})/g;
    
    const frequencies = bashCommand.match(frequencyRegex);
    const durations = bashCommand.match(durationRegex);
    const delays = bashCommand.match(delayRegex);

    console.log('---');
    console.log(frequencies?.length);
    console.log(durations?.length);
    console.log(delays?.length);
    console.log('---');
    
    return frequencies.map((frequency, index) => {
        const duration = durations[index].replace('-l ', '');
        const delay = delays?.contains(index) ? delays[index].replace('-D ', '') : null;
        frequency = frequency.replace('-f ', '');
    
        console.log(`Note(${frequency}, ${duration}, ${delay}),`);
    });
}

