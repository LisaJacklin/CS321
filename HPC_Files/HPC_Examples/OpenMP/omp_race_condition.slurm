#!/bin/bash

#SBATCH --job-name="OMP Race Condition"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:10:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="OMP_race.%j"

module list

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a

start=`date +%s`
for i in `seq 1 10`
do
    ./bin/race
done
end=`date +%s`
echo $((end-start))
