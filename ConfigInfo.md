#Config file explained

##Intro
This game comes with a configuration file so the game can be modified to your specific needs/preferences.

Here some info about that specific file.

**<u>Important:</u>** 
* The values of the file are not checked, so the game can break if you change some of the values.
* Because I used tintXML2, comments are not supported in the XML file and all settings have to be in the `<Settings>` field.

## Screen
```
<Screen>
    <Width></Width>
    <Height></Height>
    <FPS></FPS>
</Screen>
```
These are the screen parameters, they represent the settings about the screen.
The default values of the sprites and the game itself is originally designed for a 10:7 aspect ratio for the screen.

| Item   | Default Value | Unit | Type |
|--------|---------------|------|------|
| Width  | 1000          | px   | int  |
| Height | 700           | px   | int  |
| FPS    | 60            | Hz   | int  |

##Lives
```
<Lives></Lives>
```
This one is very straightforward, it's just the amount of lives the player has.

| Item   | Default Value | Type | 
|--------|---------------|------| 
| Lives  | 3             | int  | 
                           
##Speed                    
```
<Speed>
    <Player></Player>
    <Bullet></Bullet>
    <Enemy></Enemy>
    <Bonus></Bonus>
</Speed>
```
Here, the speed of all entities is declared. Do note that some of these entities don't move every frame.
The unit of the speed is the relative distance per second. 

| Item   | Default Value | Unit | Type   | 
|--------|---------------|------|--------| 
| Player | 0.5           | d/s  | double | 
| Bullet | 0.8           | d/s  | double | 
| Enemy  | 0.04          | d/s  | double | 
| Bonus  | 0.005         | d/s  | double |

##Size
```
<Size>
    <Player>
        <Width></Width>
        <Height></Height>
    </Player>
    <Enemy>
        <Width></Width>
        <Height></Height>
    </Enemy>
    <Bullets>
        <Width></Width>
        <Height></Height>
    </Bullets>
    <Bonus>
        <Width></Width>
        <Height></Height>
    </Bonus>
</Size>
```
Next up is size, there isn't much to say about this one, other than that the values are the relative distance.

| Item         | Default Value | Unit | Type   | 
|--------------|---------------|------|--------| 
| PlayerWidth  | 0.05          | d    | double | 
| PlayerHeight | 0.05          | d    | double |
| EnemyWidth   | 0.05          | d    | double | 
| EnemyHeight  | 0.04          | d    | double |
| BulletWidth  | 0.005         | d    | double | 
| BulletHeight | 0.03          | d    | double |
| BonusWidth   | 0.1           | d    | double | 
| BonusHeight  | 0.35          | d    | double |

##Cooldown
```
<Cooldown>
    <Enemy>
        <Shooting></Shooting>
        <Movement></Movement>
        <Death></Death>
    </Enemy>
    <Bonus>
        <SpawnRate></SpawnRate>
        <SpawnCooldown></SpawnCooldown>
    </Bonus>
</Cooldown>
```
The cooldowns are probably some of the safest parameters to change. 
Because they are quite different they will each be explained in the table.

| Item               | Default Value | Unit | Type   | Info
|--------------------|---------------|------|--------|------
| EnemyShooting      | 0.35          | s    | double | The time between two shots for an enemy
| EnemyMovement      | 1             | s    | double | The time between enemy movements
| EnemyDeath         | 0.5           | s    | double | How long an explosion will be shown
| BonusSpawnRate     | 5             | %    | int    | The chance of a bonusentity spawning every <i>BonusSpawnCooldown</i> seconds
| BonusSpawnCooldown | 0.25          | s    | double | See BonusSpawnRate

##Lower bound
```
<LowerBound></LowerBound>
```
If the enemies pass this line, you'll automatically lose.

| Item         | Default Value | Unit | Type   | 
|--------------|---------------|------|--------| 
| LowerBound   | 0.9           | d    | double | 

##Scores
```
<Scores>
    <E0></E0>
    <E1></E1>
    <E2></E2>
    <E3></E3>
    <E4></E4>
    <Pos></Pos>
    <Neg></Neg>
</Scores>
```
The scores you get when killing enemies. For the generic enemies (E*x*) is 0 the backmost enemy and 4 the lowest enemy.

| Item | Default Value | Type | 
|------|---------------|------| 
| E0   | 100           | int  | 
| E1   | 80            | int  |
| E2   | 60            | int  | 
| E3   | 40            | int  |
| E4   | 20            | int  | 
| Pos  | 200           | int  |
| Neg  | -200          | int  | 
