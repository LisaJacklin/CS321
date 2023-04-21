#!/bin/bash

#SBATCH --job-name="Multiple Processes"
#SBATCH --partition=debug
#SBATCH --ntasks=24
#SBATCH --tasks-per-node=24
#SBATCH --time=00:01:00
#SBATCH --mail-user=email@example.edu
#SBATCH --mail-type=BEGIN
#SBATCH --mail-type=END
#SBATCH --mail-type=FAIL
#SBATCH --output="Single_Process.%j"

#Purge and Load Modules
module purge
module load slurm
module load foss/2022a
module load Python/3.10.4

start=`date +%s`

for i in `seq 1 24`
do
python3 ../md5sum.py > "md5sum.$i" &
done
wait
end=`date +%s`
echo $((end-start))
