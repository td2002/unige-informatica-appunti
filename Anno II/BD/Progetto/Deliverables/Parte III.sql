-- PARTE III.11

-- # # # INTERROGAZIONI CARICO DI LAVORO E CREAZIONE SCHEMA FISICO # # #

SET search_path TO 'progetto52';

ANALYZE;

-- interrogazione per conoscere occupazione in memoria delle tabelle (solo quelle create)
SELECT N.nspname, C.relname, C.relpages, C.reltuples, C.relnatts, C.relhastriggers
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
WHERE N.nspname = 'progetto52'
AND relname NOT LIKE '%\_%' OR relname IN ('tabella_log')
ORDER BY relpages DESC;

-- interrogazione per conoscere indici presenti nel DBMS
SELECT N.oid, N.nspname, C.relname, C.relfilenode, C.relpages, C.reltuples,
indexrelid, indrelid, indnatts, indisunique, indisprimary, indisclustered, indkey
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
JOIN pg_index ON C.oid = indexrelid
WHERE N.nspname = 'progetto52';


-- 1) selezionare il nome scientifico e la data della prima installazione delle piante messe a dimora nell'anno scolastico 2006/2007
SELECT DISTINCT gruppo.nomescientifico, MIN(gruppo.data)
FROM gruppo
WHERE data BETWEEN '2006-09-01' AND '2007-08-31'
GROUP BY nomescientifico ORDER BY nomescientifico;

CREATE INDEX index_gruppo_data ON gruppo(data);

ANALYZE;

-- 2) selezionare tutti i sensori di rilevamento umidità e i rispettivi orti in cui sono alloggiati
SELECT orto.id, orto.nome, sensore.num, sensore.tiposensore
FROM sensore JOIN orto ON sensore.idorto = orto.id
WHERE tiposensore = 'umidita' ORDER BY orto.id, sensore.num;

CREATE INDEX index_hash_sensore_tiposensore ON sensore USING HASH(tiposensore);

ANALYZE;

-- 3) selezionare le date delle rilevazioni, in ordine cronologico, nelle quali sono presenti informazioni di temperatura estrema (maggiore di 45°C)
SELECT rilevazione.dataoraoss, informazione.tipoinformazione, informazione.valore
FROM informazione JOIN rilevazione ON informazione.idrilevazione = rilevazione.id
WHERE tipoinformazione = 'temperatura' and valore > 45
ORDER BY rilevazione.dataoraoss;

CREATE INDEX index_cluster_informazione_valore ON informazione(valore);

CLUSTER informazione USING index_cluster_informazione_valore;

ANALYZE;

-- PARTE III.12

-- # # # POLITICHE DI CONTROLLO DELL'ACCESSO # # #

-- gestoreglobale ≥ referenteistituto
-- referenteistituto ≥ referentescuola
-- referentescuola ≥ insegnante
-- insegnante ≥ studente

CREATE ROLE gestoreglobale; 
CREATE ROLE referenteistituto;
CREATE ROLE referentescuola;
CREATE ROLE insegnante;
CREATE ROLE studente;

GRANT referenteistituto TO gestoreglobale;
GRANT referentescuola TO referenteistituto;
GRANT insegnante TO referentescuola;
GRANT studente TO insegnante;

GRANT SELECT ON classe, collocazione, gruppo, informazione, orto, progetto, replica, rilevazione, sensore, specie, riassunto_biomonitoraggio TO studente;

GRANT SELECT ON referente TO insegnante;

GRANT SELECT ON persona, scuola TO referentescuola;

GRANT INSERT ON informazione, rilevazione TO studente;

GRANT INSERT ON collocazione, gruppo, replica TO insegnante;

GRANT INSERT ON classe TO referentescuola;

GRANT INSERT ON orto, persona, referente, scuola, sensore TO referenteistituto;

GRANT UPDATE ON informazione, rilevazione TO studente;

GRANT UPDATE ON collocazione, gruppo, replica TO insegnante;

GRANT UPDATE ON classe, orto, persona, sensore TO referentescuola;

GRANT UPDATE ON referente, scuola TO referenteistituto;

GRANT DELETE ON gruppo, informazione, replica, rilevazione TO insegnante;

GRANT DELETE ON classe, collocazione TO referentescuola;

GRANT DELETE ON orto, persona, referente, scuola, sensore TO referenteistituto;

GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA "progetto52" TO gestoreglobale WITH GRANT OPTION;

CREATE USER alessandro WITH
PASSWORD 'ordnassela'
IN ROLE gestoreglobale;

CREATE USER marco WITH
PASSWORD 'ocram'
IN ROLE referenteistituto;
	
CREATE USER ignazio WITH
PASSWORD 'oizangi'
IN ROLE referentescuola;
	
CREATE USER berto WITH
PASSWORD 'otreb'
IN ROLE insegnante;
	
CREATE USER giovannino WITH
PASSWORD 'oninnavoig'
IN ROLE studente;

GRANT USAGE ON SCHEMA "progetto52" TO alessandro, marco, ignazio, berto, giovannino;