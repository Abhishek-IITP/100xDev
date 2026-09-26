# hello-prisma

A minimal Prisma + PostgreSQL setup using **TypeScript**, **tsx**, and **Docker**.

---

## Prerequisites

* Node.js (v18+ recommended)
* Docker
* npm or Bun

---

## Project Setup

### 1. Initialize Project

```bash
mkdir hello-prisma
cd hello-prisma
npm init -y
# Bun equivalent:
bun init
```

### 2. Install Dependencies

```bash
npm install typescript tsx @types/node --save-dev
npx tsc --init

npm install prisma @types/node @types/pg --save-dev
npm install @prisma/client @prisma/adapter-pg pg dotenv
```

#### Bun

```bash
bun add -d typescript tsx @types/node
bunx tsc --init

bun add prisma@prev @types/pg --dev
bun add @prisma/client@7 @prisma/adapter-pg pg dotenv
```

---

## Configuration

### `tsconfig.json`

```json
{
  "compilerOptions": {
    "module": "ESNext",
    "moduleResolution": "bundler",
    "target": "ES6",
    "strict": true,
    "esModuleInterop": true
  }
}
```

### `package.json`

```json
{
  "type": "module",
  "scripts": {
    "dev": "tsx script.ts"
  }
}
```

---

## Prisma Setup

### Initialize Prisma

```bash
npx prisma init
```

#### Bun

```bash
bunx --bun prisma init --output ../generated/prisma
```

### `prisma.config.ts`

```ts
import 'dotenv/config'
import { defineConfig, env } from 'prisma/config'

export default defineConfig({
  schema: 'prisma/schema.prisma',
  migrations: {
    path: 'prisma/migrations',
  },
  datasource: {
    url: env('DATABASE_URL'),
  },
})
```

### Environment Variables

Create `.env`:

```env
DATABASE_URL="postgresql://postgres:mypassword@localhost:5432/mydb"
```

---

## Database (Docker)

```bash
docker run -e POSTGRES_PASSWORD=mypassword \
-e POSTGRES_DB=mydb \
-d -p 5432:5432 \
--name postgres-db-new \
postgres
```

### PostgreSQL Commands

Check the container status:

```bash
docker ps
```

Start or stop the PostgreSQL container:

```bash
docker start postgres-db-new
docker stop postgres-db-new
```

Open a PostgreSQL shell inside the container:

```bash
docker exec -it postgres-db-new psql -U postgres -d mydb
```

Useful `psql` commands:

```sql
\l          -- List databases
\dt         -- List tables
\q          -- Exit psql
```

---

## Prisma Schema

Update `prisma/schema.prisma` with your models.

---

## Migrations & Client

```bash
npx prisma migrate dev --name init
npx prisma generate
```

#### Bun

```bash
bunx prisma migrate dev --name init
bunx prisma generate
```

---

## Prisma Client Setup

### `lib/prisma.ts`

```ts
import 'dotenv/config'
import { PrismaPg } from '@prisma/adapter-pg'
import { PrismaClient } from '../generated/prisma/client'

const adapter = new PrismaPg({
  connectionString: process.env.DATABASE_URL!,
})

export const prisma = new PrismaClient({ adapter })
```

---

## Example Script

### `script.ts`

```ts
import { prisma } from './lib/prisma'

async function main() {
  const user = await prisma.user.create({
    data: {
      name: 'Alice',
      email: `alice${Date.now()}@prisma.io`,
      travelPlans: {
        create: {
          title: 'Japan Vacation',
          destinationCity: 'Tokyo',
          destinationCountry: 'Japan',
          startDate: new Date('2026-07-01'),
          endDate: new Date('2026-07-10'),
          budget: 2500,
        },
      },
    },
    include: {
      travelPlans: true,
    },
  })

  console.log('Created user:', user)

  const allUsers = await prisma.user.findMany({
    include: {
      travelPlans: true,
    },
  })

  console.log('All users:', JSON.stringify(allUsers, null, 2))
}

main()
  .catch(console.error)
  .finally(async () => {
    await prisma.$disconnect()
  })
```

---

## Run the App

```bash
npm run dev
```

#### Bun

```bash
bun run dev
```

---

